#include <iostream>
#include <vector>

using namespace std;

int getPivot(vector<int>& nums) {
    int start = 0, end = nums.size() - 1;
    int mid = start + (end - start) / 2;
    while(start < end) {
        if(nums[mid] >= nums[0]) {
            start = mid + 1;
        } else {
            end = mid;
        }
        mid = start + (end - start) / 2;
    }
    return start;
}

bool searchInRotatedSortedArray(vector<int>& nums, int start, int end, int k) {
    int mid;
    while(start <= end) {
        mid = start + (end - start) / 2;
        if(nums[mid] == k) {
            return true;
        } else if(nums[mid] < k) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return false;
}

int main() {
    vector<int> nums;
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    cout << "Enter elements in array: ";
    for(int i = 0; i < size; i++) {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }

    cout << "Original array: ";
    for(int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    int search_element;
    cout << "Enter the element to search: ";
    cin >> search_element;

    int pivot = getPivot(nums);
    cout << "Pivot element index: " << pivot << endl;

    bool found;
    if(search_element >= nums[pivot] && search_element <= nums[size - 1]) {
        found = searchInRotatedSortedArray(nums, pivot, size - 1, search_element);
    } else {
        found = searchInRotatedSortedArray(nums, 0, pivot - 1, search_element);
    }

    if(found) {
        cout << "Element found in the array." << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
