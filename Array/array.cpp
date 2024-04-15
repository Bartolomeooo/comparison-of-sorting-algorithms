#include <random>
#include <algorithm>
#include "array.h"

template <typename T>
array<T>::array(size_t size) {
    data_ = new T[size];
    size_ = size;
}

template <typename T>
array<T>::array(const array& other) {
    data_ = new T[other.size_];
    size_ = other.size_;
    for (size_t i = 0; i < size_; i++) {
        data_[i] = other.data_[i];
    }
}

template <typename T>
array<T>::~array() {
    delete[] data_;
}

template <typename T>
T& array<T>::operator[](size_t index) const {
    return data_[index];
}

template <typename T>
T& array<T>::operator[](size_t index) {
    return data_[index];
}

template <typename T>
void array<T>::PushBack(const T& value) {
    T* new_data = new T[size_ + 1];
    for (size_t i = 0; i < size_; i++) {
        new_data[i] = data_[i];
    }
    new_data[size_] = value;
    delete[] data_;
    data_ = new_data;
    size_++;
}

template <typename T>
void array<T>::PopBack() {
    if (size_ > 0) {
        size_--;
        T* new_data = new T[size_];
        for (size_t i = 0; i < size_; i++) {
            new_data[i] = data_[i];
        }
        delete[] data_;
        data_ = new_data;
    }
}

template <typename T>
size_t array<T>::size() const {
    return size_;
}

template <typename T>
bool array<T>::IsEmpty() const {
    return size_ == 0;
}

template <typename T>
void array<T>::fillRandom() {
    srand(time(nullptr));
    for (size_t i = 0; i < size_; ++i) {
        data_[i] = rand();
        //std::cout<<data_[i]<<std::endl;
    }
}

template <typename T>
void array<T>::fillAscending() {
    fillRandom(); // Wykorzystanie istniejącej funkcji do wypełnienia tablicy losowymi danymi
    std::sort(data_, data_ + size_); // Sortowanie tablicy w porządku rosnącym
}

template <typename T>
void array<T>::fillDescending() {
    fillRandom(); // Wykorzystanie istniejącej funkcji do wypełnienia tablicy losowymi danymi
    std::sort(data_, data_ + size_, std::greater<T>()); // Sortowanie tablicy w porządku malejącym
}


template <typename T>
void array<T>::fillPartiallySorted(double portion_sorted) {
    if (portion_sorted < 0 || portion_sorted > 1) {
        std::cerr << "Error: Portion sorted must be in the range [0, 1]." << std::endl;
        return;
    }

    fillRandom(); // Wypełnienie tablicy losowymi danymi

    size_t sorted_size = static_cast<size_t>(portion_sorted * size_);
    std::sort(data_, data_ + sorted_size); // Sortowanie tylko części tablicy
}

template <typename T>
void array<T>::resize(int newSize) {
    delete[] data_;  // Zwalnianie istniejącej tablicy
    data_ = new T[newSize];  // Alokacja nowej tablicy o zadanym rozmiarze
    size_ = newSize;  // Aktualizacja rozmiaru tablicy
}

template <typename T>
bool array<T>::isSorted() {
    for(int i = 1; i < size_; i++) {
        if(data_[i] < data_[i - 1]) return false;
    }
    return true;
}
