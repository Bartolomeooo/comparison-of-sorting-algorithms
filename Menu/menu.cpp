#include "menu.h"
#include "measurement.h"
#include "measurement.cpp"
#include "test.h"
#include "test.cpp"


void menu::showMenu() {
    int choice;
    do {
        std::cout << "Menu:\n"
                  << "1. Measurement\n"
                  << "2. Test\n"
                  << "3. Exit\n\n"
                  << "Enter your choice: ";
        std::cin >> choice;
        std::cout << "\n";

        switch(choice) {
            case 1:
                measurement::measure();
                break;
            case 2:
                int choice;
                std::cout << "Choose data type:\n"
                          << "1. Integer\n"
                          << "2. Float\n\n"
                          << "Enter your choice: ";
                std::cin >> choice;
                std::cout << "\n";

                if(choice == 1) test<int>::run();
                else if(choice == 2) test<float>::run();
                else std::cout << "Invalid choice. Please try again.\n\n";

                break;
            case 3:
                std::cout << "Exiting program...\n";
                exit(1);
            default:
                std::cout << "Invalid choice. Please try again.\n\n";
        }
    } while(choice != 3);
}