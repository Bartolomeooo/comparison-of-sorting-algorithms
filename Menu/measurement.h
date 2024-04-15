#ifndef MEASUREMENT_H
#define MEASUREMENT_H

#include "../Array/array.h" // Jeżeli array jest klasą, lepiej byłoby użyć deklaracji forward i include w pliku .cpp
#include "../SortingAlgorithms/SortingAlgorithms.h" // To samo dotyczy SortingAlgorithms

class measurement {
public:
    static void measure();

private:

    template <typename T> static void fillArray(array<T>& arr, const std::string& distribution);
    template <typename T> static void measureSortingTime(void (*sortingFunction)(array<T>&), array<T>& arr, const std::string& distribution);
    static void measureSortingTimeWithPivot(void (*sortingFunction)(array<int>&, int, int), array<int>& arr, int low, int high, const std::string& distribution);
};

#endif // MEASUREMENT_H

