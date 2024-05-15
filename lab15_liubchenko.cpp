#include <iostream>
#include <cmath>
using namespace std;

void swap(double* a, double* b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(double arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void selectionSort(double arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(&arr[i], &arr[min_idx]);
    }
}

void insertionSort(double arr[], int n) {
    for (int i = 1; i < n; i++) {
        double key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int partition(double arr[], int low, int high) {
    double pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] >= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(double arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    const int size = 20;
    double a[size] = { 3, 2, 7, 1, 5, 9, 4, 8, 6, 0,
                      11, 13, 15, 10, 12, 14, 16, 18, 17, 19 };

    quickSort(a, 0, size - 1);

    double b[size];
    int b_index = 0;
    for (int i = 0; i < size; i++) {
        if (fmod(a[i], 2) != 0) {
            b[b_index++] = a[i];
        }
    }

    cout << "Sorted array b containing odd elements of array a in descending order:" << endl;
    for (int i = 0; i < b_index; i++) {
        cout << b[i] << " ";
    }
    cout << endl;

    return 0;
}

