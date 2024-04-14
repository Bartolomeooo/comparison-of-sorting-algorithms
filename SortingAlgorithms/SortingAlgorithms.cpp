#ifndef SORTINGALGORITHMS_TPP
#define SORTINGALGORITHMS_TPP

#include "SortingAlgorithms.h"
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <algorithm>

template <typename T>
void SortingAlgorithms<T>::shellSortGap1(array<T>& arr) {
    size_t n = arr.size();
    for (size_t gap = n / 2; gap > 0; gap /= 2) {
        for (size_t i = gap; i < n; i += 1) {
            T temp = arr[i];
            size_t j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

template <typename T>
void SortingAlgorithms<T>::shellSortGap2(array<T>& arr) {
    size_t n = arr.size();
    for (size_t gap = n / 2; gap > 0; gap = gap == 2 ? 1 : gap * 5 / 11) {
        for (size_t i = gap; i < n; i += 1) {
            T temp = arr[i];
            size_t j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

template <typename T>
void SortingAlgorithms<T>::insertionSort(array<T>& arr) {
    size_t n = arr.size();
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

template <typename T>
void SortingAlgorithms<T>::heapify(array<T>& arr, size_t n, size_t i) {
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

template <typename T>
void SortingAlgorithms<T>::heapSort(array<T>& arr) {
    size_t n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

template <typename T>
void SortingAlgorithms<T>::quickSortLeftPivot(array<T>& arr, int low, int high) {
    if (low < high) {
        int pi = partitionLeft(arr, low, high);
        quickSortLeftPivot(arr, low, pi - 1);
        quickSortLeftPivot(arr, pi + 1, high);
    }
}

template <typename T>
void SortingAlgorithms<T>::quickSortRightPivot(array<T>& arr, int low, int high) {
    if (low < high) {
        int pi = partitionRight(arr, low, high);
        quickSortRightPivot(arr, low, pi - 1);
        quickSortRightPivot(arr, pi + 1, high);
    }
}

template <typename T>
void SortingAlgorithms<T>::quickSortMiddlePivot(array<T>& arr, int low, int high) {
    if (low < high) {
        int pi = partitionMiddle(arr, low, high);
        quickSortMiddlePivot(arr, low, pi - 1);
        quickSortMiddlePivot(arr, pi + 1, high);
    }
}

template <typename T>
void SortingAlgorithms<T>::quickSortRandomPivot(array<T>& arr, int low, int high) {
    if (low < high) {
        int pi = partitionRandom(arr, low, high);
        quickSortRandomPivot(arr, low, pi - 1);
        quickSortRandomPivot(arr, pi + 1, high);
    }
}

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

template <typename T>
int SortingAlgorithms<T>::partitionRandom(array<T>& arr, int low, int high) {
    srand(time(NULL));
    size_t random = low + rand() % (high - low);
    std::swap(arr[random], arr[high]);
    return partition(arr, low, high);
}

template <typename T>
int SortingAlgorithms<T>::partitionLeft(array<T>& arr, int low, int high) {
    return partition(arr, low, high);
}

template <typename T>
int SortingAlgorithms<T>::partitionRight(array<T>& arr, int low, int high) {
    return partition(arr, low, high);
}

template <typename T>
int SortingAlgorithms<T>::partitionMiddle(array<T>& arr, int low, int high) {
    int mid = low + (high - low) / 2;
    std::swap(arr[mid], arr[high]);
    return partition(arr, low, high);
}
#endif // SORTINGALGORITHMS_TPP
