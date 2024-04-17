#ifndef TEST_H
#define TEST_H

#include "../Array/array.h"  // Zakładamy, że array.cpp zawiera definicję i implementację dynamicznej tablicy
#include "../SortingAlgorithms/SortingAlgorithms.h"  // Zakładamy, że zawiera implementacje algorytmów sortowania

class test {
private:
    static array<int> currentArrayInt;  // Current integer array
    static array<float> currentArrayFloat;  // Current float
    static bool useFloat;  //
    template <typename T> static void displaySortedArray(const array<T>& arr);
    static void loadFromFile();
    static void generateArray();
    static void displayArray();
    static void sortArray();
    static void chooseDataType();

public:
    static void run();
};

#endif // TEST_H
