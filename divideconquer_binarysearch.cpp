#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int key) {
    if (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] > key) {
            return binarySearch(arr, low, mid - 1, key);
        } else {
            return binarySearch(arr, mid + 1, high, key);
        }
    }
    return -1;
}

int main() {
    int size, key;
    cout << "Enter the number of elements: ";
    cin >> size;
    int arr[size];
    cout << "Enter the sorted elements: ";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
    cout << "Enter the value to search for: ";
    cin >> key;

    int result = binarySearch(arr, 0, size - 1, key);
    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }
    return 0;
}

