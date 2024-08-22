#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int value, weight;
    Item(int v, int w) : value(v), weight(w) {}
};

bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item>& items) {
    sort(items.begin(), items.end(), compare);
    int currentWeight = 0;
    double finalValue = 0.0;

    for (vector<Item>::iterator it = items.begin(); it != items.end(); ++it) {
        Item& item = *it;
        if (currentWeight + item.weight <= W) {
            currentWeight += item.weight;
            finalValue += item.value;
        } else {
            int remain = W - currentWeight;
            finalValue += item.value * ((double)remain / item.weight);
            break;
        }
    }

    return finalValue;
}

int main() {
    int W;
    cout << "Enter knapsack capacity: ";
    cin >> W;
    int n;
    cout << "Enter number of items: ";
    cin >> n;
    vector<Item> items;
    cout << "Enter value and weight of each item:" << endl;
    for (int i = 0; i < n; ++i) {
        int value, weight;
        cin >> value >> weight;
        items.push_back(Item(value, weight));
    }

    cout << "Maximum value in Knapsack = " << fractionalKnapsack(W, items) << endl;
    return 0;
}
