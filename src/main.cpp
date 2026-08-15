/*
 * SmartHealth System
 * Main Application - Ultra-Modern CLI Edition
 */

#include <iostream>
#include <limits>
#include <iomanip>
#include <thread>
#include <chrono>
#ifdef _WIN32
#include <windows.h>
#endif

#include "doctor.h"
#include "patient.h"
#include "hospital.h"

using namespace std;

// ANSI Color Palette (Modern Dark Theme Styling)
const string RESET = "\033[0m";
const string BOLD = "\033[1m";
const string DIM = "\033[2m";
const string CYAN = "\033[36m";
const string BLUE = "\033[34m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string RED = "\033[31m";
const string MAGENTA = "\033[35m";
const string BG_DARK = "\033[40m";

void enableAnsiSupport() {
#ifdef _WIN32
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    if (hOut != INVALID_HANDLE_VALUE && GetConsoleMode(hOut, &dwMode)) {
        SetConsoleMode(hOut, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
    }
#endif
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pauseScreen() {
    cout << "\n  " << DIM << "Press [ENTER] to continue..." << RESET;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// Modern Dashboard Header Card
void displayHeader(string subtitle) {
    cout << CYAN << BOLD << "\n  ======================================================\n";
    cout << "   SMARTHEALTH CLINICAL MANAGEMENT SYSTEM v2.6          \n";
    cout << "   " << BLUE << left << setw(50) << subtitle << CYAN << " |\n";
    cout << "  ======================================================\n" << RESET;
}

void welcome() {
    clearScreen();
    enableAnsiSupport();

    cout << "\n\n  " << CYAN << BOLD << "[ ~ ] Booting SmartHealth Core Modules";
    for (int i = 0; i < 3; ++i) {
        this_thread::sleep_for(chrono::milliseconds(250));
        cout << ".";
        cout.flush();
    }
    cout << RESET << "\n";
    this_thread::sleep_for(chrono::milliseconds(300));

    clearScreen();
    displayHeader("SYSTEM INITIALIZED");
    cout << "\n  " << GREEN << "[SUCCESS]" << RESET << " All security protocols & databases loaded.\n";
}

int getChoice() {
    int choice;
    cout << "\n  " << YELLOW << "-> Enter selection: " << RESET;
    if (!(cin >> choice)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return -1;
    }
    return choice;
}

void patientMenu() {
    Patient patient;

    while (true) {
        clearScreen();
        displayHeader("PORTAL / PATIENT MANAGEMENT");

        cout << "\n  " << MAGENTA << "[1]" << RESET << " Register New Patient Profile\n";
        cout << "  " << MAGENTA << "[2]" << RESET << " Secure Patient Portal Login\n";
        cout << "  " << DIM << "[3] Return to Previous Menu" << RESET << "\n";

        int choice = getChoice();

        switch (choice) {
        case 1:
            clearScreen();
            displayHeader("PATIENT REGISTRATION");
            patient.registration();
            pauseScreen();
            break;

        case 2:
            clearScreen();
            displayHeader("PATIENT AUTHENTICATION");
            patient.login();
            pauseScreen();
            break;

        case 3:
            return;

        default:
            cout << "\n  " << RED << "[ERROR]" << RESET << " Invalid selection. Please choose [1-3].\n";
            pauseScreen();
        }
    }
}

void mainMenu() {
    Doctor doctor;
    Hospital hospital;

    while (true) {
        clearScreen();
        displayHeader("MAIN DASHBOARD");

        cout << "\n  " << BOLD << "AUTHENTICATED PORTALS:" << RESET << "\n";
        cout << "  " << CYAN << "[1]" << RESET << " Doctor Portal           " << DIM << "(Clinical records & diagnosis)" << RESET << "\n";
        cout << "  " << CYAN << "[2]" << RESET << " Patient Portal          " << DIM << "(Appointments & history)" << RESET << "\n";
        cout << "  " << CYAN << "[3]" << RESET << " Hospital Admin Portal   " << DIM << "(System management)" << RESET << "\n";
        cout << "\n  " << RED  << "[4]" << RESET << " Exit System\n";

        int choice = getChoice();

        switch (choice) {
        case 1:
            clearScreen();
            displayHeader("PORTAL / DOCTOR ACCESS");
            doctor.login();
            pauseScreen();
            break;

        case 2:
            patientMenu();
            break;

        case 3:
            clearScreen();
            displayHeader("PORTAL / HOSPITAL ADMIN");
            hospital.login();
            pauseScreen();
            break;

        case 4:
            return;

        default:
            cout << "\n  " << RED << "[ERROR]" << RESET << " Invalid option. Please choose [1-4].\n";
            pauseScreen();
        }
    }
}

int main() {
    welcome();
    pauseScreen();
    mainMenu();

    clearScreen();
    cout << CYAN << BOLD << "\n  ======================================================\n";
    cout << "   Session Terminated Safely. Thank you!              \n";
    cout << "   SmartHealth System v2.6. All rights reserved.        \n";
    cout << "  ======================================================\n" << RESET << "\n";

    return 0;
}
