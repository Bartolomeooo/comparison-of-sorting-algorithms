/*#include "test.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "../Array/array.cpp"
#include "../SortingAlgorithms/SortingAlgorithms.cpp"

void test::run() {
    chooseDataType();
    int choice;
    do {
        std::cout << "Menu:\n"
                  << "1. Load array from file\n"
                  << "2. Generate random array\n"
                  << "3. Display current array\n"
                  << "4. Sort current array\n"
                  << "5. Exit\n"
                  << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                loadFromFile();
                break;
            case 2:
                generateArray();
                break;
            case 3:
                displayArray();
                break;
            case 4:
                sortArray();
                break;
            case 5:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
}

void test::chooseDataType() {
    int choice;
    std::cout << "Choose data type:\n"
              << "1. Integer\n"
              << "2. Float\n"
              << "Enter your choice: ";
    std::cin >> choice;
    useFloat = (choice == 2);
}

void test::loadFromFile() {
    std::string filename;
    std::cout << "Enter filename: ";
    std::cin >> filename;
    std::ifstream file(filename);

    if (file.is_open()) {
        int size;
        file >> size;
        if (useFloat) {
            array<int> newArrayFloat(size);
            currentArrayInt = newArrayFloat;
            for (int i = 0; i < size; i++) {
                file >> currentArrayFloat[i];
            }
        } else {
            array<int> newArrayInt(size);
            currentArrayInt = newArrayInt;
            for (int i = 0; i < size; i++) {
                file >> currentArrayInt[i];
            }
        }
        file.close();
        std::cout << "Array loaded successfully.\n";
    } else {
        std::cout << "Failed to open file.\n";
    }
}

void test::generateArray() {
    int size;
    std::cout << "Enter size of array: ";
    std::cin >> size;
    if (useFloat) {
        array<int> newArrayFloat(size);
        currentArrayInt = newArrayFloat;
        for (int i = 0; i < size; i++) {
            currentArrayFloat[i] = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX/100.0));
        }
    } else {
        array<int> newArrayInt(size);
        currentArrayInt = newArrayInt;
        for (int i = 0; i < size; i++) {
            currentArrayInt[i] = rand() % 100;  // Random numbers between 0 and 99
        }
    }
    std::cout << "Array generated successfully.\n";
}

void test::displayArray() {
    if (useFloat) {
        for (int i = 0; i < currentArrayFloat.size(); i++) {
            std::cout << currentArrayFloat[i] << " ";
        }
    } else {
        for (int i = 0; i < currentArrayInt.size(); i++) {
            std::cout << currentArrayInt[i] << " ";
        }
    }
    std::cout << "\n";
}

void test::sortArray() {
    std::cout << "Select sorting algorithm:\n"
              << "1. Insertion Sort (int)\n"
              << "2. Shell sort gap 1\n"
              << "3. Shell sort gap 2\n"
              << "4. Heap Sort\n"
              << "5. Quicksort (Left Pivot)\n"
              << "6. Quicksort (Right Pivot)\n"
              << "7. Quicksort (Middle Pivot)\n"
              << "8. Quicksort (Random Pivot)\n"
              << "Enter your choice: ";
    int choice;
    std::cin >> choice;

    if (useFloat) {
        // Assuming each sorting algorithm is templated to work with float as well
        switch (choice) {
            case 1:
                SortingAlgorithms<float>::insertionSort(currentArrayFloat);
                break;
            case 2:
                SortingAlgorithms<float>::shellSortGap1(currentArrayFloat);
                break;
            case 3:
                SortingAlgorithms<float>::shellSortGap2(currentArrayFloat);
                break;
            case 4:
                SortingAlgorithms<float>::heapSort(currentArrayFloat);
                break;
            case 5:
                SortingAlgorithms<float>::quickSortLeftPivot(currentArrayFloat, 0, currentArrayFloat.size() - 1);
                break;
            case 6:
                SortingAlgorithms<float>::quickSortRightPivot(currentArrayFloat, 0, currentArrayFloat.size() - 1);
                break;
            case 7:
                SortingAlgorithms<float>::quickSortMiddlePivot(currentArrayFloat, 0, currentArrayFloat.size() - 1);
                break;
            case 8:
                SortingAlgorithms<float>::quickSortRandomPivot(currentArrayFloat, 0, currentArrayFloat.size() - 1);
                break;
            default:
                std::cout << "Invalid choice.\n";
        }
    } else {
        switch (choice) {
            case 1:
                SortingAlgorithms<int>::insertionSort(currentArrayInt);
                break;
            case 2:
                SortingAlgorithms<int>::shellSortGap1(currentArrayInt);
                break;
            case 3:
                SortingAlgorithms<int>::shellSortGap2(currentArrayInt);
                break;
            case 4:
                SortingAlgorithms<int>::heapSort(currentArrayInt);
                break;
            case 5:
                SortingAlgorithms<int>::quickSortLeftPivot(currentArrayInt, 0, currentArrayInt.size() - 1);
                break;
            case 6:
                SortingAlgorithms<int>::quickSortRightPivot(currentArrayInt, 0, currentArrayInt.size() - 1);
                break;
            case 7:
                SortingAlgorithms<int>::quickSortMiddlePivot(currentArrayInt, 0, currentArrayInt.size() - 1);
                break;
            case 8:
                SortingAlgorithms<int>::quickSortRandomPivot(currentArrayInt, 0, currentArrayInt.size() - 1);
                break;
            default:
                std::cout << "Invalid choice.\n";
        }
    }
    displayArray(); // Show sorted array
}*/
