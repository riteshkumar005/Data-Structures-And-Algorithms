#include <iostream>

using namespace std;

bool isSorted(int *arr, int size) {
    if (size == 0 || size == 1) return true;

    if (arr[0] > arr[1]) {
        return false;
    } else {
        return isSorted(arr + 1, size - 1);
    }
}

int main() {
    int arr[] = {2, 4, 6, 9, 12};  // Correct array with 5 elements
    int size = sizeof(arr) / sizeof(arr[0]);

    if (isSorted(arr, size)) {
        cout << "Array is sorted" << endl;
    } else {
        cout << "Array is not sorted" << endl;
    }

    return 0;
}
