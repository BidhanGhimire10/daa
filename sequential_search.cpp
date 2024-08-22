#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n, key;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "\nEnter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\nEnter the element to search: ";
    cin >> key;

    int result = linearSearch(arr, n, key);
    if(result == -1) {
        cout << "\nElement not found.";
    } else {
        cout << "\nElement found at index " << result;
    }
    return 0;
}
