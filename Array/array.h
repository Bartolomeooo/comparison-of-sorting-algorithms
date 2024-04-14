#ifndef COMPARISON_OF_SORTING_ALGORITHMS_ARRAY_H
#define COMPARISON_OF_SORTING_ALGORITHMS_ARRAY_H

#include <iostream>

template <typename T>
class array {
public:
    // Constructors
    array() = default;
    explicit array(size_t size);
    array(const array& other);

    // Destructor
    ~array();

    // Methods of access
    T& operator[](size_t index) const;
    T& operator[](size_t index);

    // Modyfing methods
    void PushBack(const T& value);
    void PopBack();

    // Additional methods
    size_t size() const;
    bool IsEmpty() const;
    bool isSorted();

    // New methods for array filling
    void fillRandom();
    void fillAscending();
    void fillDescending();
    void fillPartiallySorted(double portion_sorted);

private:
    T* data_;
    size_t size_;
};

#endif
