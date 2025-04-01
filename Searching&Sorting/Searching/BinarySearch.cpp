#include <iostream>
#include <vector>

using namespace std;


int BinarySearch(vector<int>& nums, int key){
    int start = 0, end = nums.size() - 1;

    int mid = start + (end - start)/2;

    while(start < end){
        if(nums[mid] == key){
            return mid;
        }
        else if(nums[mid] < key){
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return -1;  // Element not found in the array

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

    int Index = BinarySearch(nums, key);
    cout<<"Searching at index "<<Index<<endl;

    return 0;
}