#include <iostream>
#include <vector>

using namespace std;

void LinearSearch(vector<int>& nums, int e) {
    int found = 0;
    int index = -1;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == e) {
            found = 1;
            index = i;
            break;
        }
    }

    if (found) {
        cout << "Element found at index: " << index << endl;
    } else {
        cout << "Element not found in the array: -1" << endl;
    }
}

int main() {
    vector<int> nums;
    int size, key;

    cout << "Enter the number of elements in the vector: ";
    cin >> size;

    cout << "Enter the elements: ";
    for (int i = 0; i < size; i++) {
       
        int temp;
        cin >> temp;
        nums.push_back(temp);  
    }

    cout << "Original array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Which element you want to search for? ";
    cin >> key;

    LinearSearch(nums, key);

    return 0;
}
