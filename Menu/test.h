#ifndef TEST_H
#define TEST_H

#include "../Array/array.h"  // Zakładamy, że array.cpp zawiera definicję i implementację dynamicznej tablicy
#include "../SortingAlgorithms/SortingAlgorithms.h"  // Zakładamy, że zawiera implementacje algorytmów sortowania

template <typename T>
class test {
private:
    static array<T> currentArray;
    static void displaySortedArray(const array<T>& arr);
    static void loadFromFile();
    static void generateArray();
    static void displayArray();
    static void sortArray();
    static void validateSorting(array<T>& arr);

public:
    static void run();
};

#endif // TEST_H
