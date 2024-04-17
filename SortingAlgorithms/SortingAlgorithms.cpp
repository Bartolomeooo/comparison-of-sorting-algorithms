#ifndef SORTINGALGORITHMS_TPP
#define SORTINGALGORITHMS_TPP

#include "SortingAlgorithms.h"
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <algorithm>

// Shell sort with a gap of n/2
template <typename T>
void SortingAlgorithms<T>::shellSortGap1(array<T>& arr) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            T temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// Shell sort with a gap of n5/11
template <typename T>
void SortingAlgorithms<T>::shellSortGap2(array<T>& arr) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap = gap == 2 ? 1 : gap * 5 / 11) {
        for (int i = gap; i < n; i += 1) {
            T temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// Insertion sort
template <typename T>
void SortingAlgorithms<T>::insertionSort(array<T>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        T key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Reshape into a heap data structure
template <typename T>
void SortingAlgorithms<T>::heapify(array<T>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Heap sort
template <typename T>
void SortingAlgorithms<T>::heapSort(array<T>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Quick sort with a left pivot
template <typename T>
void SortingAlgorithms<T>::quickSortLeftPivot(array<T>& arr, int low, int high) {
    if (low < high) {
        int pi = partitionLeft(arr, low, high);
        quickSortLeftPivot(arr, low, pi - 1);
        quickSortLeftPivot(arr, pi + 1, high);
    }
}

// Quick sort with a right pivot
template <typename T>
void SortingAlgorithms<T>::quickSortRightPivot(array<T>& arr, int low, int high) {
    if (low < high) {
        int pi = partitionRight(arr, low, high);
        quickSortRightPivot(arr, low, pi - 1);
        quickSortRightPivot(arr, pi + 1, high);
    }
}

// Quick sort with a middle pivot
template <typename T>
void SortingAlgorithms<T>::quickSortMiddlePivot(array<T>& arr, int low, int high) {
    if (low < high) {
        int pi = partitionMiddle(arr, low, high);
        quickSortMiddlePivot(arr, low, pi - 1);
        quickSortMiddlePivot(arr, pi + 1, high);
    }
}

// Quick sort with a random pivot
template <typename T>
void SortingAlgorithms<T>::quickSortRandomPivot(array<T>& arr, int low, int high) {
    if (low < high) {
        int pi = partitionRandom(arr, low, high);
        quickSortRandomPivot(arr, low, pi - 1);
        quickSortRandomPivot(arr, pi + 1, high);
    }
}

// Partition for quick sort
template <typename T>
int SortingAlgorithms<T>::partition(array<T>& arr, int low, int high) {
    T pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Partition for quick sort with a random pivot
template <typename T>
int SortingAlgorithms<T>::partitionRandom(array<T>& arr, int low, int high) {
    srand(time(NULL));
    int random = low + rand() % (high - low);
    std::swap(arr[random], arr[high]);
    return partition(arr, low, high);
}

// Partition for quick sort with a left pivot
template <typename T>
int SortingAlgorithms<T>::partitionLeft(array<T>& arr, int low, int high) {
    std::swap(arr[low], arr[high]);
    return partition(arr, low, high);
}

// Partition for quick sort with a right pivot
template <typename T>
int SortingAlgorithms<T>::partitionRight(array<T>& arr, int low, int high) {
    return partition(arr, low, high);
}

// Partition for quick sort with a middle pivot
template <typename T>
int SortingAlgorithms<T>::partitionMiddle(array<T>& arr, int low, int high) {
    int mid = low + (high - low) / 2;
    std::swap(arr[mid], arr[high]);
    return partition(arr, low, high);
}
#endif // SORTINGALGORITHMS_TPP
