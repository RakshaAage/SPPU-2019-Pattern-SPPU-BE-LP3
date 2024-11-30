//Write a program for analysis of quick sort

#include <iostream>
using namespace std;

// Global variable to count the number of comparisons
int comparisonCount = 0;

// Function to partition the array based on the pivot element
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choosing the last element as pivot
    int i = low - 1;  // Index of smaller element

    // Traverse the array and rearrange elements based on pivot
    for (int j = low; j <= high - 1; j++) {
        comparisonCount++;  // Increment comparison count
        // If current element is smaller than the pivot, swap it
        if (arr[j] < pivot) {
            i++;  // Move the boundary of smaller elements
            swap(arr[i], arr[j]);  // Swap elements
        }
    }
    // Place pivot element in its correct sorted position
    swap(arr[i + 1], arr[high]);
    return i + 1;  // Return the index of the pivot
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  // Partition the array and get pivot index
        quickSort(arr, low, pi - 1);  // Recursively sort elements before pivot
        quickSort(arr, pi + 1, high); // Recursively sort elements after pivot
    }
}

// Function to print the array elements
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Main function
int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];  // Input elements
    }

    cout << "Original Array: ";
    printArray(arr, n);  // Print original array

    quickSort(arr, 0, n - 1);  // Perform Quick Sort

    cout << "Sorted Array: ";
    printArray(arr, n);  // Print sorted array

    cout << "Total number of comparisons: " << comparisonCount << endl;

    return 0;
}

/*
Sample Input:
Enter the number of elements: 6
Enter the elements: 10 7 8 9 1 5

Expected Output:
Original Array: 10 7 8 9 1 5
Sorted Array: 1 5 7 8 9 10
Total number of comparisons: 11
*/
