#include "Menu/menu.h"

int main() {
    menu::showMenu(); // Wywołanie metody showMenu() z klasy menu
    int n = 14;
    array<int> arr(n);
    arr.fillPartiallySorted(0.33);
    for(int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    return 0;
}