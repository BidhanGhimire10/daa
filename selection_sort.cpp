#include <iostream>
using namespace std;

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;
    int arr[size];
    cout << "Enter the elements: ";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    selectionSort(arr, size);
    cout << "Sorted array: ";
    printArray(arr, size);
    return 0;
}
