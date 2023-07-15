#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& sortedArray, int target) {
    int left = 0;
    int right = sortedArray.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (sortedArray[mid] == target)
            return mid;

        if (sortedArray[mid] < target)
            left = mid + 1;

        else
            right = mid - 1;
    }

    return -1;
}

int main() {
    std::vector<int> array = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int target = 12;

    int index = binarySearch(array, target);
    if (index != -1)
        std::cout << "Element found at index " << index << std::endl;
    else
        std::cout << "Element not found" << std::endl;

    return 0;
}
