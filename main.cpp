#include "Menu/menu.h"
#include "Menu/menu.cpp"
//#include "Array/array.h"
//#include "Array/array.cpp"

int main() {
    menu::showMenu(); // Wywołanie metody showMenu() z klasy menu

    array<float>arr(10);
    arr.fillRandom();
    for(int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n\n\n";
    SortingAlgorithms<float>::quickSortRandomPivot(arr, 0, 9);
    for(int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    return 0;
}