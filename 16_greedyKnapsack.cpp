// Write a code to implement fractional knapsack problem.
#include <iostream>
#include <algorithm>
using namespace std;
struct Item {
    int weight;
    int profit;
    double ratio;
};

bool compare(Item a, Item b) {                       // Function to compare two items based on their profit/weight ratio
    return a.ratio > b.ratio;
}

double fractionalKnapsack(Item items[], int n, int capacity) {
    for (int i = 0; i < n; i++) {           
        items[i].ratio = (double)items[i].profit / items[i].weight;
    }
    sort(items, items + n, compare);                   // Sort items by their profit/weight ratio in descending order
    double total_profit = 0;
    for (int i = 0; i < n; i++) {
        if (items[i].weight <= capacity) {
            capacity -= items[i].weight;
            total_profit += items[i].profit;
        } 
        else {
            total_profit += items[i].profit * ((double)capacity / items[i].weight);
            break;
        }
    }
    return total_profit;
}

int main() {
    int n, capacity;
    cout << "Enter the number of items: ";
    cin >> n;
    Item items[n];
    cout << "Enter the weight and profit of each item:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << " - Weight: ";
        cin >> items[i].weight;
        cout << "Item " << i + 1 << " - Profit: ";
        cin >> items[i].profit;
        cout << endl;
    }
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;
    double maxProfit = fractionalKnapsack(items, n, capacity);
    cout << "\nMaximum profit is: " << maxProfit << endl;
    return 0;
}
