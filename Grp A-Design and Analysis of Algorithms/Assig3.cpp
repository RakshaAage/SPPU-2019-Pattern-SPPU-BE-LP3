// Write a program to solve a fractional Knapsack problem using a greedy method.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an item with weight and value
struct Item {
    int weight;
    int value;

    Item(int w, int v) : weight(w), value(v) {}
};

// Comparator function to sort items by value-to-weight ratio
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// Function to solve Fractional Knapsack problem
double fractionalKnapsack(int capacity, vector<Item>& items) {
    // Sort items by value-to-weight ratio in descending order
    sort(items.begin(), items.end(), compare);

    double maxValue = 0.0;

    // Traverse items and add to knapsack
    for (const auto& item : items) {
        if (capacity >= item.weight) {
            // Take the whole item
            capacity -= item.weight;
            maxValue += item.value;
        } else {
            // Take a fraction of the item
            maxValue += item.value * ((double)capacity / item.weight);
            break;
        }
    }

    return maxValue;
}

int main() {
    int n, capacity;
    cout << "Enter the total number of items: ";
    cin >> n;
    cout << "Enter the maximum capacity of the knapsack: ";
    cin >> capacity;

    vector<Item> items;

    for (int i = 0; i < n; i++) {
        int value, weight;
        cout << "Enter value and weight for item " << i + 1 << ": ";
        cin >> value >> weight;
        items.push_back(Item(weight, value));
    }

    double maxValue = fractionalKnapsack(capacity, items);
    cout << "Maximum value in Fractional Knapsack = " << maxValue << endl;

    return 0;
}


// Enter the total number of items: 3
// Enter the maximum capacity of the knapsack: 50
// Enter value and weight for item 1: 60 10
// Enter value and weight for item 2: 100 20
// Enter value and weight for item 3: 120 30

// Maximum value in Fractional Knapsack = 240
