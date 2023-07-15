#include <iostream>
#include <vector>

using namespace std;
void merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> left(mid - low + 1);
    vector<int> right(high - mid);
   for (int i = 0; i < left.size(); ++i)
        left[i] = arr[low + i];
    for (int i = 0; i < right.size(); ++i)
        right[i] = arr[mid + 1 + i];
   
    int i = 0;  
    int j = 0; 
    int k = low; 
   while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            ++i;
        } else {
            arr[k] = right[j];
            ++j;
        }
        ++k;
    }
    while (i < left.size()) {
        arr[k] = left[i];
        ++i;
        ++k;
    }
    while (j < right.size()) {
        arr[k] = right[j];
        ++j;
        ++k;
    }
}

void mergeSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}
void printArray(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {7, 2, 9, 4, 5, 3, 1, 6, 8};
    int size = arr.size();

    cout << "Original array: ";
    printArray(arr);

    mergeSort(arr, 0, size - 1);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}

