#include <iostream>
#include <vector>
using namespace std;
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
     vector<int> arr = { 4, 2, 7, 5, 1, 3, 6};
    int n = arr.size();
    cout << "Original array: ";
    printArray(arr);
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
