#include <iostream>
#include <vector>

using namespace std;
void bubbleSort(vector<int>& arr) {
    int size = arr.size();
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) 
        {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void printArray(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {7, 2, 9, 4, 5, 3, 1, 6, 8};

    cout << "Original array: ";
    printArray(arr);

    bubbleSort(arr);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
