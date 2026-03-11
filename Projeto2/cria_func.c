/*
LORENA SILVEIRA DOS SANTOS 2312667 3WC
 */
#include "cria_func.h"
#include <stdio.h>
#include <string.h>
#include <stdint.h>
void cria_func (void* f, DescParam params[], int n, unsigned char codigo[]){
    unsigned char guardaParam [] = {0x7d, 0x75, 0x55};
    int paramCount = 0, p = 0, i;

    codigo[p++] = 0x55; 
    codigo[p++] = 0x48; codigo[p++] = 0x89; codigo[p++] = 0xe5; 
    codigo[p++] = 0x48; codigo[p++] = 0x83; codigo[p++] = 0xec;codigo[p++] = 0x20; 
    
    codigo[p++] = 0x48; codigo[p++] = 0x89; codigo[p++] = 0x7d;codigo[p++] = 0xf8; 
    codigo[p++] = 0x48; codigo[p++] = 0x89; codigo[p++] = 0x75;codigo[p++] = 0xf0; 
    codigo[p++] = 0x48; codigo[p++] = 0x89; codigo[p++] = 0x55;codigo[p++] = 0xe8; 
  
    for(i = 0; i < n; i++ ){
        if (params[i].orig_val == FIX) {
            if (params[i].tipo_val == INT_PAR){
                if(i==0){
                    codigo[p++] = 0xbf;
                }
                else if(i==1){
                    codigo[p++] = 0xbe; 
                }
                else{
                    codigo[p++] = 0xba;
                }
            

                codigo[p++] = (params[i].valor.v_int & 0xff);
                codigo[p++] = (params[i].valor.v_int >> 8) & 0xff;
                codigo[p++] = (params[i].valor.v_int >> 16) & 0xff;
                codigo[p++] = (params[i].valor.v_int >> 24) & 0xff;
        }

        else{
            codigo[p++] = 0x48;
            if(i==0){
                codigo[p++] = 0xbf;
            }
            else if(i==1){
                codigo[p++] = 0xbe;
            }
            else{
                codigo[p++] = 0xba;
            }

            uintptr_t end_v_ptr = (uintptr_t)params[i].valor.v_ptr;
            for (int j = 0; j < 8; j++) {
                    codigo[p++] = (end_v_ptr >> (j * 8)) & 0xff;
                }
        }

        } 
        else if (params[i].orig_val == IND) {
            if(params[i].tipo_val == INT_PAR){
                codigo[p++] = 0x49; codigo[p++] = 0xb8;
                
                memcpy(&codigo[p], &params[i].valor.v_ptr, sizeof(void *));
                p += sizeof(void *); 
                
                codigo[p++] = 0x41;
                codigo[p++] = 0x8b;
               
                if (i==0){
                    codigo[p++] = 0x38;
                } else if(i==1){
                    codigo[p++] = 0x30;
                }
                else{
                    codigo[p++] = 0x10;
                }

            }
            else{
                codigo[p++] = 0x49;
                codigo[p++] = 0xb8;
                memcpy(&codigo[p], params[i].valor.v_ptr, sizeof(void *));
                p += sizeof(void *);
                
                codigo[p++] = 0x4c;
                codigo[p++] = 0x89;
                
                if(i==0){
                    codigo[p++] = 0xc7;
                }
                else if(i==1){
                    codigo[p++] = 0xc6;
                }
                else{
                    codigo[p++] = 0xc2;
                }
            }

        }
        else{
            if (params[i].tipo_val == INT_PAR) {
                codigo[p++] = 0x8b;
                codigo[p++] = guardaParam[i];

                if(paramCount == 0){
                    codigo[p++] = 0xf8; 
                }
                else if (paramCount == 1){
                    codigo[p++] = 0xf0; 

                }
                else if (paramCount == 2){
                    codigo[p++] = 0xe8; 

                }
            }
            else{
                codigo[p++] = 0x48; codigo[p++] = 0x8b; 
                codigo[p++] = guardaParam[i];

                if(paramCount == 0){
                        codigo[p++] = 0xf8;
                }
                else if( paramCount == 1){
                    codigo[p++] = 0xf0;
                }
                else{
                    codigo[p++]= 0xe8;
                }
            }
            paramCount++;
        }
    }
        

    codigo[p++] = 0x48;codigo[p++] = 0xb8;
    memcpy(&codigo[p], &f, sizeof(void *));
    p+= sizeof(void*);
    codigo[p++] = 0xff; codigo[p++] = 0xd0;

    codigo[p++] = 0xc9;
    codigo[p++] = 0xc3;

    return;
}
