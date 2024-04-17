#ifndef MEASUREMENT_H
#define MEASUREMENT_H

#include "../Array/array.h"
#include "../SortingAlgorithms/SortingAlgorithms.h"

class measurement {
public:
    static void measure();

private:
    template <typename T> static void fillArray(array<T>& arr, const std::string& distribution);
    template <typename T> static void measureSortingTime(void (*sortingFunction)(array<T>&), array<T>& arr, const std::string& distribution);
    static void measureSortingTimeWithPivot(void (*sortingFunction)(array<int>&, int, int), array<int>& arr, int low, int high, const std::string& distribution);
};

#endif // MEASUREMENT_H

