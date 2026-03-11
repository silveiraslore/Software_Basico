/*Lorena_Silveira_dos_Santos 2312667 33WC*/

#include <stdio.h>
#include <stdlib.h>
#include "converteutf832.h"


int convUtf8p32(FILE* arquivo_entrada, FILE* arquivo_saida) {
	unsigned char byte;
	unsigned int secondByte, thirdByte, fourthByte, byteEm32;

	unsigned char BOM[4] = { 0xFF, 0xFE, 0x00, 0x00 };
	if (fwrite(BOM, sizeof(BOM), 1, arquivo_saida) != 1) {
		fprintf(stderr, "Falha ao escrever BOM em arquivo_saida.\n");
		return -1;
	}


	while (fread(&byte, 1, 1, arquivo_entrada) == 1) {
		if ((byte & 0x80) == 0x00) {
			byteEm32 = (unsigned int)byte;
			if (fwrite(&byteEm32, sizeof(byteEm32), 1, arquivo_saida) != 1) {
				fprintf(stderr, "Falha ao escrever %x em UTF32\n", byteEm32);
				return -1;
			}
		}
		else if ((byte & 0xE0) == 0xC0) {
			if (fread(&secondByte, 1, 1, arquivo_entrada) != 1) {
				fprintf(stderr, "Falha ao ler bytes\n");
				return -1;
			}
			byteEm32 = ((unsigned int)(byte & 0x1F) << 6) | (secondByte & 0x3F);
			if (fwrite(&byteEm32, sizeof(byteEm32), 1, arquivo_saida) != 1) {
				fprintf(stderr, "Falha ao escrever %x em UTF32\n", byteEm32);
				return -1;
			}
		}
		else if ((byte & 0xF0) == 0xE0) {
			if (fread(&secondByte, 1, 1, arquivo_entrada) != 1 ||
				fread(&thirdByte, 1, 1, arquivo_entrada) != 1) {
				fprintf(stderr, "Falha ao ler bytes\n");
				return -1;
			}
			byteEm32 = ((unsigned int)(byte & 0x0F) << 12) |
				((unsigned int)(secondByte & 0x3F) << 6) |
				(thirdByte & 0x3F);
			if (fwrite(&byteEm32, sizeof(byteEm32), 1, arquivo_saida) != 1) {
				fprintf(stderr, "Falha ao escrever %x em UTF32\n", byteEm32);
				return -1;
			}
		}
		else if ((byte & 0xF8) == 0xF0) {
			if (fread(&secondByte, 1, 1, arquivo_entrada) != 1 ||
				fread(&thirdByte, 1, 1, arquivo_entrada) != 1 ||
				fread(&fourthByte, 1, 1, arquivo_entrada) != 1) {
				fprintf(stderr, "Falha ao ler bytes\n");
				return -1;
			}
			byteEm32 = ((unsigned int)(byte & 0x07) << 18) | ((unsigned int)(secondByte & 0x3F) << 12) | ((unsigned int)(thirdByte & 0x3F) << 6) | (fourthByte & 0x3F);
			if (fwrite(&byteEm32, sizeof(byteEm32), 1, arquivo_saida) != 1) {
				fprintf(stderr, "Falha ao escrever %x em UTF32\n", byteEm32);
				return -1;
			}
		}
		else {
			fprintf(stderr, "byte invalido encontrado: 0x%02X\n", byte);
			return -1;
		}
	}

	if (ferror(arquivo_entrada)) {
		fprintf(stderr, "Falha ao ler arquivo de entrada UTF8\n");
		return -1;
	}


	return 0;
}



int convUtf32p8(FILE* arquivo_entrada, FILE* arquivo_saida) {
	unsigned int valorEm32;
	int isLittleEndian;
	unsigned char utf8[4], BOM[4];

	if (fread(&BOM, 1, 4, arquivo_entrada) != 4) {
		fprintf(stderr, "valor BOM invalido");
		return -1;
	}

	
	if (BOM[0] == 0x00 && BOM[1] == 0x00 && BOM[2] == 0xFE && BOM[3] == 0xFF) {
		isLittleEndian = 0;
	}
	else if (BOM[0] == 0xFF && BOM[1] == 0xFE && BOM[2] == 0x00 && BOM[3] == 0x00) {
		isLittleEndian = 1;
	}
	else {
		fprintf(stderr, "BOM nao encontrado ou invalido\n");
		return -1;
	}

	while (fread(&valorEm32, sizeof(valorEm32), 1, arquivo_entrada) == 1) {
		if (!isLittleEndian) {
			valorEm32 =
				((valorEm32 & 0x000000FF) << 24) |
				((valorEm32 & 0x0000FF00) << 8) |
				((valorEm32 & 0x00FF0000) >> 8) |
				((valorEm32 & 0xFF000000) >> 24);
		}

		if (valorEm32 <= 0x7F) {
			utf8[0] = (unsigned char)valorEm32;
			if (fwrite(utf8, 1, 1, arquivo_saida) != 1) {
				fprintf(stderr, "erro ao converter para utf8");
				return -1;
			}
		}
		else if (valorEm32 <= 0x7FF) {
			utf8[0] = 0xC0 | ((valorEm32 >> 6) & 0x1F);
			utf8[1] = 0x80 | (valorEm32 & 0x3F);
			if (fwrite(utf8, 1, 2, arquivo_saida) != 2) {
				fprintf(stderr, "erro ao converter para utf8");
				return -1;
			};
		}

		else if (valorEm32 <= 0xFFFF) {
			utf8[0] = 0xE0 | ((valorEm32 >> 12) & 0x0F);
			utf8[1] = 0x80 | ((valorEm32 >> 6) & 0x3F);
			utf8[2] = 0x80 | (valorEm32 & 0x3F);
			if (fwrite(utf8, 1, 3, arquivo_saida) != 3) {
				fprintf(stderr, "erro ao converter para utf8");
				return -1;
			};
		}

		else if (valorEm32 <= 0x10FFFF) {
			utf8[0] = 0xF0 | ((valorEm32 >> 18) & 0x07);
			utf8[1] = 0x80 | ((valorEm32 >> 12) & 0x3F);
			utf8[2] = 0x80 | ((valorEm32 >> 6) & 0x3F);
			utf8[3] = 0x80 | (valorEm32 & 0x3F);
			if (fwrite(utf8, 1, 4, arquivo_saida) != 4) {
				fprintf(stderr, "erro ao converter para utf8");
				return -1;
			};
		}
		else {
			fprintf(stderr, "Caractere Unicode invalido: U+%X\n", valorEm32);
			return -1;
		}
	}

	return 0;
}