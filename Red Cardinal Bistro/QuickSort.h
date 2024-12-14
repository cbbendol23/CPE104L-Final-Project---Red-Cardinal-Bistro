// QuickSort.h
#pragma once

#include <vector>
#include <string>
#include <utility>

inline int partitionPrice(std::vector<std::pair<std::string, double>>& items, int low, int high) {
    double pivot = items[high].second;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (items[j].second < pivot) {
            i++;
            std::swap(items[i], items[j]);
        }
    }
    std::swap(items[i + 1], items[high]);
    return i + 1;
}

inline void quickSortPrice(std::vector<std::pair<std::string, double>>& items, int low, int high) {
    if (low < high) {
        int pi = partitionPrice(items, low, high);
        quickSortPrice(items, low, pi - 1);
        quickSortPrice(items, pi + 1, high);
    }
}

inline int partitionName(std::vector<std::pair<std::string, double>>& arr, int low, int high) {
    std::string pivot = arr[high].first;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].first < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Quick sort function for sorting alphabetically by name
inline void quickSortName(std::vector<std::pair<std::string, double>>& arr, int low, int high) {
    if (low < high) {
        int pi = partitionName(arr, low, high);

        quickSortName(arr, low, pi - 1);
        quickSortName(arr, pi + 1, high);
    }
}