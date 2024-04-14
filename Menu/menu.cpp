#include "menu.h"
#include "measurement.h"
#include "test.h"
//#include "test.cpp"
//#include "test.h"

void menu::showMenu() {
    int choice;
    do {
        std::cout << "Menu:\n"
                  << "1. Measurement\n"
                  << "2. Test\n"
                  << "3. Exit\n"
                  << "Enter your choice: ";
        std::cin >> choice;

        switch(choice) {
            case 1:
                measurement::measure();
                break;
            case 2:
                //test::run();
                break;
            case 3:
                std::cout << "Exiting program...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while(choice != 3);
}