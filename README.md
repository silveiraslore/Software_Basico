# Software_Basico
## Basic Software – Labs & Projects

This repository contains all laboratory exercises and projects developed during the **Basic Software** course, with a focus on low-level programming and system-level concepts.

## 📖 Overview

This repository documents practical implementations of fundamental software concepts, including:

* 🧪 Laboratory assignments
* 💻 Two major projects
* ⚙️ Low-level manipulation of memory, data, and execution

## 📂 Repository Structure

```bash
.
├── labs/
│   ├── lab01/
│   ├── lab02/
│   └── ...
├── Projeto1/
├── Projeto2/
└── README.md
```

## 💻 Project 1 – UTF-8 ↔ UTF-32 Converter

### 📌 Description

This project implements a **character encoding converter** between UTF-8 and UTF-32 using pure C.

It reads and writes binary files and manually encodes/decodes Unicode characters.

### ⚙️ Features

* Conversion:

  * UTF-8 → UTF-32
  * UTF-32 → UTF-8
* Handles **BOM (Byte Order Mark)**
* Supports UTF-8 sequences from 1 to 4 bytes
* Detects **endianness** (little vs big endian)
* Uses bitwise operations for encoding/decoding
* Includes error handling for invalid input

### 🧠 Concepts Applied

* Bitwise operations
* File I/O (`fread`, `fwrite`)
* Unicode encoding
* Endianness
* Binary data processing

## 💻 Project 2 – Dynamic Function Generator (Code Injection)

### 📌 Description

This project implements a **runtime function generator** in C by manually writing **machine code (x86-64)** into a byte array.

The generated code dynamically calls a target function with parameters defined at runtime.

### ⚙️ Features

* Generates executable machine code at runtime
* Supports different parameter types:

  * Integers
  * Pointers
* Handles parameter passing via registers (calling convention)
* Supports:

  * Fixed values (`FIX`)
  * Indirect values (`IND`)
  * Parameters passed through function arguments
* Uses low-level memory manipulation (`memcpy`, raw bytes)
* Calls functions via generated assembly instructions

### 🧠 Concepts Applied

* Assembly-level programming (x86-64)
* Calling conventions (register usage like RDI, RSI, RDX)
* Function pointers
* Memory layout and stack frames
* Code generation at runtime
* Pointer manipulation

### ⚠️ Important Notes

* This project relies on **low-level system behavior** and may be platform-dependent
* Typically requires:
  * Linux environment
  * Executable memory permissions (e.g., `mmap` / `mprotect`)
* Intended strictly for **educational purposes**

## 🛠️ Technologies Used

* **Language:** C
* **Tools:** GCC, Makefile (if applicable)
* **Environment:** Linux / Unix-based systems

## ▶️ How to Run

Compile (example):

```bash
gcc *.c -o program
```

Run:

```bash
./program
```

## 🎯 Purpose

This repository serves as:

* A record of academic work
* A demonstration of low-level and systems programming skills
* Practical experience with memory, encoding, and execution

## 📌 Final Remarks

These projects emphasize **understanding how software works at a low level**, including:

* How data is represented in memory
* How functions are executed
* How instructions are translated into machine code

## 📄 License

This repository is for educational purposes.
