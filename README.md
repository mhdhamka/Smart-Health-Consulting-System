<div align="center">

# SmartHealth System

A console-based healthcare management system developed in **C++** as part of an **Object-Oriented Software Development course**.

![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)
![Compiler](https://img.shields.io/badge/Compiler-GCC-orange)
![Environment](https://img.shields.io/badge/Environment-MSYS2%20UCRT64-purple)
![Platform](https://img.shields.io/badge/Platform-Console-success)
![Programming](https://img.shields.io/badge/Programming-OOP-green)

</div>

---

This project was originally developed as an academic coursework project and has been **restructured and enhanced** to improve code organization, maintainability, and software development practices.

The system demonstrates fundamental **Object-Oriented Programming (OOP)** concepts, including:

- Classes and Objects
- Encapsulation
- Inheritance
- File Handling
- Input Validation
- Modular Programming using Header Files
- Separation of Source and Header Files

---

# Features

## Patient Module
- Patient Registration
- Patient Login
- View Patient Profile
- Update Patient Profile
- View Medical Records

## Doctor Module
- Doctor Login
- View Patient Records
- Add Medical Records
- Edit Medical Records
- Remove Medical Records

## Hospital Administrator Module
- Administrator Login
- Manage Hospital Information

## Appointment & Consultation Module
- Appointment Booking
- Appointment Management
- Consultation Services
- Payment Management

## System Features
- File-based Data Storage
- Input Validation
- Modular Program Structure
- Console-based User Interface

---

# Project Structure

```
SmartHealth-System
│
├── include
│   ├── appointment.h
│   ├── bool.h
│   ├── doctor.h
│   ├── hospital.h
│   ├── patient.h
│   ├── payment.h
│   ├── record.h
│   └── user.h
│
├── src
│   ├── main.cpp
│   ├── appointment.cpp
│   ├── bool.cpp
│   ├── doctor.cpp
│   ├── hospital.cpp
│   ├── patient.cpp
│   ├── payment.cpp
│   ├── record.cpp
│   └── user.cpp
│
├── data
│   ├── PatientRegistration.txt
│   ├── Appointment.txt
│   ├── Record.txt
│   └── Payment.txt
│
└── README.md
```

---

# Technologies Used

- **Programming Language:** C++
- **Compiler:** GCC (MinGW-w64)
- **Development Environment:** Visual Studio Code
- **Build Environment:** MSYS2 UCRT64
- **Programming Paradigm:** Object-Oriented Programming (OOP)
- **Storage Method:** Text File-Based Database

---

# Development Environment Setup

This project is developed and tested using:

## MSYS2 UCRT64 Environment

MSYS2 provides a Unix-like development environment on Windows with the UCRT64 toolchain for compiling C++ applications.

### Required Software

- Visual Studio Code
- C/C++ Extension
- MSYS2
- UCRT64 GCC Compiler


### Install GCC Compiler

Open MSYS2 UCRT64 terminal:

```bash
pacman -S mingw-w64-ucrt-x86_64-gcc
```

Verify compiler installation:

```bash
g++ --version
```

---

# How to Run

## Option 1: Visual Studio Code + MSYS2 UCRT64 (Recommended)

### Clone Repository

```bash
git clone https://github.com/mhdhamka/SmartHealth-System.git
```

Navigate to project folder:

```bash
cd SmartHealth-System
```

---

## Compile Program

Run the following command from the project root directory:

```bash
g++ src/*.cpp -Iinclude -o SmartHealth.exe
```

### Compilation Explanation

```
src/*.cpp
```

Compile all C++ source files inside the `src` folder.

```
-Iinclude
```

Specify the location of header files.

```
-o SmartHealth.exe
```

Generate the executable file.

---

## Run Program

Using MSYS2 UCRT64:

```bash
./SmartHealth.exe
```

Using Windows Command Prompt:

```cmd
SmartHealth.exe
```

---

# Default Login Credentials

## Doctor Account

```
Username : PDC1365
Password : 74251

Doctor Name : Lamine Hamka
Specialization : Paediatric
```

---

## Hospital Administrator Account

```
Username : Marc Cucurella
Password : 10024

Hospital Name : Nurulain Basirah
```

---

# Notes

- The project uses `.cpp` files for class implementation and `.h` files for class declarations.
- All system data is stored locally using text files inside the `data` folder.
- Run the program from the project root directory to ensure file paths work correctly.
- The system is designed for educational purposes and demonstrates basic software development practices.

---

# Project Restructuring and Improvements

The original coursework version was restructured and improved by:

- Organizing source files into separate `src` and `include` directories
- Improving class organization and modularity
- Removing duplicated code
- Improving file handling methods
- Updating compilation workflow using MSYS2 UCRT64
- Improving project documentation
- Enhancing maintainability and readability

---

# License

This project was developed for **educational and personal software development purposes**.

The original version was created as part of an academic project, while this enhanced version was independently restructured to practice:

- Object-Oriented Programming
- Modular Software Design
- File-Based Data Management
- C++ Application Development

---
