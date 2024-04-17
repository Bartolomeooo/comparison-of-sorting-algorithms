#include "test.h"
#include <iostream>
#include <fstream>
#include <string>

template <typename T>
array<T> test<T>::currentArray;

// The main method
template <typename T>
void test<T>::run() {
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
                displayArray(currentArray);
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

// Load data from a file
template <typename T>
void test<T>::loadFromFile() {
    std::string filename;
    std::cout << "Enter filename: ";
    std::cin >> filename;
    std::ifstream file(filename);
    if (file.is_open()) {
        int size;
        file >> size;

        currentArray.resize(size);
        for (int i = 0; i < size; i++) {
            file >> currentArray[i];
        }

        file.close();
        std::cout << "Array loaded successfully.\n\n";
    } else {
        std::cout << "Failed to open file.\n\n";
    }
}

// Generate an array with random values
// The size of the array is specified by the user
template <typename T>
void test<T>::generateArray() {
    int size;
    std::cout << "Enter size of the array: ";
    std::cin >> size;
    std::cout << "\n";
    currentArray.resize(size);
    currentArray.fillRandom();
    std::cout << "Array generated successfully.\n\n";
}

// Sort the array
template <typename T>
void test<T>::sortArray() {
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


    array<T> tempArray = currentArray; // Create a local copy of the array

    switch (choice) {
        case 1:
            SortingAlgorithms<T>::insertionSort(tempArray);
            break;
        case 2:
            SortingAlgorithms<T>::shellSortGap1(tempArray);
            break;
        case 3:
            SortingAlgorithms<T>::shellSortGap2(tempArray);
            break;
        case 4:
            SortingAlgorithms<T>::heapSort(tempArray);
            break;
        case 5:
            SortingAlgorithms<T>::quickSortLeftPivot(tempArray, 0, tempArray.size() - 1);
            break;
        case 6:
            SortingAlgorithms<T>::quickSortRightPivot(tempArray, 0, tempArray.size() - 1);
            break;
        case 7:
            SortingAlgorithms<T>::quickSortMiddlePivot(tempArray, 0, tempArray.size() - 1);
            break;
        case 8:
            SortingAlgorithms<T>::quickSortRandomPivot(tempArray, 0, tempArray.size() - 1);
            break;
        default:
            std::cout << "Invalid choice.\n";
            return;
    }
    validateSorting(tempArray);
    displayArray(tempArray);

    std::cout << "\n";
}

// Display an array.
template <typename T>
void test<T>::displayArray(const array<T>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

// Validate whether the sorted array is indeed in sorted order and inform the user of the result
template <typename T>
void test<T>::validateSorting(array<T>& arr) {
    if (arr.isSorted()) {
        std::cout << "The array has been sorted successfully.\n";
        return;
    }
    std::cout << "The array hasn't been sorted successfully.\n";
    std::cout << "\n";
}