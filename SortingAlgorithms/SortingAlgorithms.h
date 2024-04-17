#ifndef SORTINGALGORITHMS_H
#define SORTINGALGORITHMS_H

#include "../Array/array.h"

template <typename T>
class SortingAlgorithms {
public:
    static void shellSortGap1(array<T>& arr);
    static void shellSortGap2(array<T>& arr);
    static void insertionSort(array<T>& arr);
    static void heapSort(array<T>& arr);
    static void quickSortLeftPivot(array<T>& arr, int low, int high);
    static void quickSortRightPivot(array<T>& arr, int low, int high);
    static void quickSortMiddlePivot(array<T>& arr, int low, int high);
    static void quickSortRandomPivot(array<T>& arr, int low, int high);

private:
    static void heapify(array<T>& arr, int n, int i);
    static int partition(array<T>& arr, int low, int high);
    static int partitionRandom(array<T>& arr, int low, int high);
    static int partitionLeft(array<T>& arr, int low, int high);
    static int partitionRight(array<T>& arr, int low, int high);
    static int partitionMiddle(array<T>& arr, int low, int high);
};

#endif // SORTINGALGORITHMS_H