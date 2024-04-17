#include "test.h"
#include <iostream>
#include <fstream>
#include <string>
#include "../Array/array.cpp"
#include "../SortingAlgorithms/SortingAlgorithms.cpp"

array<int> test::currentArrayInt(0);
array<float> test::currentArrayFloat(0);
bool test::useFloat = false;


void test::run() {
    chooseDataType();
    int choice;
    do {
        std::cout << "Menu:\n"
                  << "1. Load array from file\n"
                  << "2. Generate random array\n"
                  << "3. Display current array\n"
                  << "4. Sort current array\n"
                  << "5. Exit\n\n"
                  << "Enter your choice: ";
        std::cin >> choice;
        std::cout << "\n";


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
              << "2. Float\n\n"
              << "Enter your choice: ";
    std::cin >> choice;
    std::cout << "\n";
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
            currentArrayFloat.resize(size);
            for (int i = 0; i < size; i++) {
                file >> currentArrayFloat[i];
            }
        } else {
            currentArrayInt.resize(size);
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
    std::cout << "Enter size of the array: ";
    std::cin >> size;
    std::cout << "\n";
    if (useFloat) {
        currentArrayFloat.resize(size);
        currentArrayFloat.fillRandom();
    } else {
        currentArrayInt.resize(size);
        currentArrayInt.fillRandom();
    }
    std::cout << "Array generated successfully.\n\n";
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
    std::cout << "\n\n";
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
              << "8. Quicksort (Random Pivot)\n\n"
              << "Enter your choice: ";
    int choice;
    std::cin >> choice;
    std::cout << "\n";


    if (useFloat) {
        // Tworzenie lokalnej kopii
        array<float> tempArray = currentArrayFloat;
        switch (choice) {
            case 1:
                SortingAlgorithms<float>::insertionSort(tempArray);
                break;
            case 2:
                SortingAlgorithms<float>::shellSortGap1(tempArray);
                break;
            case 3:
                SortingAlgorithms<float>::shellSortGap2(tempArray);
                break;
            case 4:
                SortingAlgorithms<float>::heapSort(tempArray);
                break;
            case 5:
                SortingAlgorithms<float>::quickSortLeftPivot(tempArray, 0, tempArray.size() - 1);
                break;
            case 6:
                SortingAlgorithms<float>::quickSortRightPivot(tempArray, 0, tempArray.size() - 1);
                break;
            case 7:
                SortingAlgorithms<float>::quickSortMiddlePivot(tempArray, 0, tempArray.size() - 1);
                break;
            case 8:
                SortingAlgorithms<float>::quickSortRandomPivot(tempArray, 0, tempArray.size() - 1);
                break;
            default:
                std::cout << "Invalid choice.\n";
                return;
        }
        displaySortedArray(tempArray);
    } else {
        // Tworzenie lokalnej kopii
        array<int> tempArray = currentArrayInt;
        switch (choice) {
            case 1:
                SortingAlgorithms<int>::insertionSort(tempArray);
                break;
            case 2:
                SortingAlgorithms<int>::shellSortGap1(tempArray);
                break;
            case 3:
                SortingAlgorithms<int>::shellSortGap2(tempArray);
                break;
            case 4:
                SortingAlgorithms<int>::heapSort(tempArray);
                break;
            case 5:
                SortingAlgorithms<int>::quickSortLeftPivot(tempArray, 0, tempArray.size() - 1);
                break;
            case 6:
                SortingAlgorithms<int>::quickSortRightPivot(tempArray, 0, tempArray.size() - 1);
                break;
            case 7:
                SortingAlgorithms<int>::quickSortMiddlePivot(tempArray, 0, tempArray.size() - 1);
                break;
            case 8:
                SortingAlgorithms<int>::quickSortRandomPivot(tempArray, 0, tempArray.size() - 1);
                break;
            default:
                std::cout << "Invalid choice.\n";
                return;
        }
        displaySortedArray(tempArray);
    }
    std::cout << "\n";
}


template <typename T>
void test::displaySortedArray(const array<T>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}