#ifndef TEST_H
#define TEST_H

#include "../Array/array.h"  // Zakładamy, że array.cpp zawiera definicję i implementację dynamicznej tablicy
#include "../SortingAlgorithms/SortingAlgorithms.h"  // Zakładamy, że zawiera implementacje algorytmów sortowania

class test {
private:
    static array<int> currentArrayInt;  // Aktualna tablica dla int
    static array<float> currentArrayFloat;  // Aktualna tablica dla float
    static bool useFloat;  // Flaga wskazująca czy używamy tablicy typu float

public:
    static void run();
    static void loadFromFile();
    static void generateArray();
    static void displayArray();
    static void sortArray();
    static void chooseDataType();
};

#endif // TEST_H
