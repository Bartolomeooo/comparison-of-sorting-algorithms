#ifndef COMPARISON_OF_SORTING_ALGORITHMS_ARRAY_H
#define COMPARISON_OF_SORTING_ALGORITHMS_ARRAY_H

#include <iostream>

template <typename T>
class array {
public:
    // Constructors
    array() = default;
    explicit array(int size);
    array(const array& other);

    // Destructor
    ~array();

    // Methods of access
    T& operator[](int index) const;
    T& operator[](int index);

    // Modyfing methods
    void PushBack(const T& value);
    void PopBack();
    void resize(int newSize);

    // Additional methods
    int size() const;
    bool IsEmpty() const;
    bool isSorted();

    // Methods for array filling
    void fillRandom();
    void fillAscending();
    void fillDescending();
    void fillPartiallySorted(double portionToBeSorted);

private:
    T* data_;
    size_t size_;
};

#endif