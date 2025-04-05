#include <iostream>
#include <vector>

using namespace std;

int  getPivot(vector<int>& nums){
    int start = 0, end = nums.size()-1;
    int mid = start + (end - start)/2;
    while(start < end){
        if(nums[mid] >= nums[0]){
            start = mid + 1;
        }
        else {
           end = mid;
        }
        mid = start + (end - start)/2;
    }
    return start;
}

bool searchInRotatedSortedArray(vector<int>& nums, int k, int pivot){
    int start = 0, end = nums.size()-1;

    int mid  = start + (end - start)/2;
    while(start <= end){
        if(nums[mid] == k){
            return true;
        }
        else if(nums[0] <= nums[mid]){
            start = mid + 1;
        }
        else{
            end = mid ;
        }
        mid  = start + (end - start)/2;

    }
    return false;

}

int main() {
    vector<int> nums;
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int search_element ;
    cout <<"Enter  elements in array: ";
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
    cout << "Enter the element to search: ";
    cin >> search_element;

    cout <<"Pivot element";
    int pivot = getPivot(nums);

    int PeakIndex = searchInRotatedSortedArray(nums, search_element, pivot);
    cout << "Peak index: " << PeakIndex << endl;



    return 0;
}