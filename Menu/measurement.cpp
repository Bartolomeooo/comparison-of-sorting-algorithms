#include "measurement.h"
#include "../Array/array.cpp"
#include "../SortingAlgorithms/SortingAlgorithms.cpp"

void measurement::measure() {
    int algorithmChoice;
    do {
        std::cout << "Select sorting algorithm:\n"
                  << "1. Insertion Sort (int)\n"
                  << "2. Insertion Sort (float)\n"
                  << "3. Shell sort gap 1\n"
                  << "4. Shell sort gap 2\n"
                  << "5. Heap Sort\n"
                  << "6. Quicksort (Left Pivot)\n"
                  << "7. Quicksort (Right Pivot)\n"
                  << "8. Quicksort (Middle Pivot)\n"
                  << "9. Quicksort (Random Pivot)\n"
                  << "10. Exit\n\n"
                  << "Enter your choice: ";
        std::cin >> algorithmChoice;

        if(algorithmChoice == 10) break;

        // Array sizes to benchmark
        std::vector<int> array_sizes = {1000, 2000, 5000, 10000, 20000, 50000, 100000};

        // Initial data distributions
        std::vector<std::string> data_distributions = {
                "Random",
                "Ascending",
                "Descending",
                "Partially Sorted (33%)",
                "Partially Sorted (66%)"
        };

        for (const auto& distribution : data_distributions) {
            std::cout << "\nData distribution: " << distribution << "\n";

            for (const auto& size : array_sizes) {
                std::cout << size << ": ";

                if (algorithmChoice == 1) {
                    array<int> arr(size);
                    measureSortingTime(SortingAlgorithms<int>::insertionSort, arr, distribution);
                } else if (algorithmChoice == 2) {
                    array<float> arr(size);
                    measureSortingTime(SortingAlgorithms<float>::insertionSort, arr, distribution);
                } else if (algorithmChoice >= 3 && algorithmChoice <= 9) {
                    array<int> arr(size);
                    switch(algorithmChoice) {
                        case 3:
                            measureSortingTime(SortingAlgorithms<int>::shellSortGap1, arr, distribution);
                            break;
                        case 4:
                            measureSortingTime(SortingAlgorithms<int>::shellSortGap2, arr, distribution);
                            break;
                        case 5:
                            measureSortingTime(SortingAlgorithms<int>::heapSort, arr, distribution);
                            break;
                        case 6:
                            measureSortingTimeWithPivot(SortingAlgorithms<int>::quickSortLeftPivot, arr, 0, size - 1, distribution);
                            break;
                        case 7:
                            measureSortingTimeWithPivot(SortingAlgorithms<int>::quickSortRightPivot, arr, 0, size - 1, distribution);
                            break;
                        case 8:
                            measureSortingTimeWithPivot(SortingAlgorithms<int>::quickSortMiddlePivot, arr, 0, size - 1, distribution);
                            break;
                        case 9:
                            measureSortingTimeWithPivot(SortingAlgorithms<int>::quickSortRandomPivot, arr, 0, size - 1, distribution);
                            break;
                    }
                }
            }
        }
        std::cout << "\n";
    } while (algorithmChoice != 10);
}

template <typename T>
void measurement::fillArray(array<T>& arr, const std::string& distribution) {
    if (distribution == "Random") {
        arr.fillRandom();
    } else if (distribution == "Ascending") {
        arr.fillAscending();
    } else if (distribution == "Descending") {
        arr.fillDescending();
    } else if (distribution == "Partially Sorted (33%)") {
        arr.fillPartiallySorted(0.33);
    } else if (distribution == "Partially Sorted (66%)") {
        arr.fillPartiallySorted(0.66);
    }
}

template <typename T>
void measurement::measureSortingTime(void (*sortingFunction)(array<T>&), array<T>& arr, const std::string& distribution) {
    const int num_measurements = 10;
    double total_time = 0.0;
    for (int i = 0; i < num_measurements; ++i) {
        fillArray(arr, distribution); // Fill array with the specified distribution before each measurement
        auto start_time = std::chrono::high_resolution_clock::now();
        sortingFunction(arr);
        auto end_time = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end_time - start_time;
        total_time += elapsed.count();
    }
    double average_time = (total_time * 1000) / num_measurements;
    std::cout << average_time << " ms\n";
    //std::cout << arr.isSorted() << "\n";
}

void measurement::measureSortingTimeWithPivot(void (*sortingFunction)(array<int>&, int, int), array<int>& arr, int low, int high, const std::string& distribution) {
    const int num_measurements = 10;
    double total_time = 0.0;
    for (int i = 0; i < num_measurements; ++i) {
        fillArray(arr, distribution); // Fill array with the specified distribution before each measurement
        auto start_time = std::chrono::high_resolution_clock::now();
        sortingFunction(arr, low, high);
        auto end_time = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end_time - start_time;
        total_time += elapsed.count();
        //std::cout << arr.isSorted() << "\n";
    }
    double average_time = (total_time * 1000) / num_measurements;
    std::cout << average_time << " ms\n";
}

