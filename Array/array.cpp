#include <random>
#include <algorithm>
#include "array.h"

// Constructor
template <typename T>
array<T>::array(int size) {
    data_ = new T[size];
    size_ = size;
}

// Copying constructor
template <typename T>
array<T>::array(const array& other) {
    data_ = new T[other.size_];
    size_ = other.size_;
    for (int i = 0; i < size_; i++) {
        data_[i] = other.data_[i];
    }
}

// Destructor
template <typename T>
array<T>::~array() {
    delete[] data_;
}

// Method of access
template <typename T>
T& array<T>::operator[](int index) const {
    return data_[index];
}

// Method of access
template <typename T>
T& array<T>::operator[](int index) {
    return data_[index];
}

// Push back an element to the last position
template <typename T>
void array<T>::PushBack(const T& value) {
    T* newData = new T[size_ + 1];
    for (int i = 0; i < size_; i++) {
        newData[i] = data_[i];
    }
    newData[size_] = value;
    delete[] data_;
    data_ = newData;
    size_++;
}

// Pop back the last element
template <typename T>
void array<T>::PopBack() {
    if (size_ > 0) {
        size_--;
        T* newData = new T[size_];
        for (int i = 0; i < size_; i++) {
            newData[i] = data_[i];
        }
        delete[] data_;
        data_ = newData;
    }
}

// Return the size of the array
template <typename T>
int array<T>::size() const {
    return size_;
}

// Check if the array is empty
template <typename T>
bool array<T>::IsEmpty() const {
    return size_ == 0;
}

// Fill the array with random values
template <typename T>
void array<T>::fillRandom() {
    srand(time(nullptr));
    for (int i = 0; i < size_; ++i) {
        data_[i] = ((float)rand() / RAND_MAX) * 10000; // Generate random values (maximum 10000)
    }
}

// Fill the array with ascending values
template <typename T>
void array<T>::fillAscending() {
    fillRandom();
    std::sort(data_, data_ + size_);
}

// Fill the array with descending values
template <typename T>
void array<T>::fillDescending() {
    fillRandom();
    std::sort(data_, data_ + size_, std::greater<T>());
}

// Fill the array with a portion of sorted data and fill the rest with higher unsorted values
template <typename T>
void array<T>::fillPartiallySorted(double portionToBeSorted) {
    srand(time(nullptr));
    if (portionToBeSorted < 0 || portionToBeSorted > 1) {
        std::cerr << "Error: Portion sorted must be in the range [0, 1]." << std::endl;
        return;
    }

    int sortedSize = portionToBeSorted * size_;
    for (int i = 0; i < sortedSize; ++i) {
        data_[i] = i + 1;
    }
    for (int i = sortedSize; i < size_; ++i) {
        data_[i] = ((float)rand() / RAND_MAX) * (size_ - sortedSize) + sortedSize + 1;
    }
}

// Resize the array
template <typename T>
void array<T>::resize(int newSize) {
    if (newSize < 0) {
        std::cerr << "Error: New size cannot be negative." << std::endl;
        return;
    }
    delete[] data_;
    data_ = new T[newSize];
    size_ = newSize;
}

// Check if the array is sorted
template <typename T>
bool array<T>::isSorted() {
    for(int i = 1; i < size_; i++) {
        if(data_[i] < data_[i - 1]) return false;
    }
    return true;
}