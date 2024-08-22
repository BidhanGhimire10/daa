#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to partition the array around a pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Function to partition the array with a random pivot
int randomizedPartition(int arr[], int low, int high) {
    int n = high - low + 1;
    int pivotIdx = low + rand() % n;
    swap(arr[pivotIdx], arr[high]);
    return partition(arr, low, high);
}

// Quickselect function to find the k-th smallest element
int quickSelect(int arr[], int low, int high, int k) {
    if (low <= high) {
        int pi = randomizedPartition(arr, low, high);

        if (pi == k - 1) {
            return arr[pi];
        } else if (pi > k - 1) {
            return quickSelect(arr, low, pi - 1, k);
        } else {
            return quickSelect(arr, pi + 1, high, k);
        }
    }
    return INT_MAX; // If k is out of bounds
}

int main() {
    srand(time(0));
    int size, k;
    cout << "Enter the number of elements: ";
    cin >> size;
    int arr[size];
    cout << "Enter the elements: ";
    for (int i = 0; i < size; ++i) cin >> arr[i];
    cout << "Enter the value of k (1-based index): ";
    cin >> k;

    if (k > 0 && k <= size) {
        int result = quickSelect(arr, 0, size - 1, k);
        cout << "The " << k << "-th smallest element is: " << result << endl;
    } else {
        cout << "k is out of bounds" << endl;
    }

    return 0;
}
