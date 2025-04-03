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

int main() {
    vector<int> nums;
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    cout <<"Enter the number of elements (Pivot in an array): ";
    for(int i = 0; i < size; i++) {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }

    int pivotElement = getPivot(nums);
    cout << "Pivot element: " <<pivotElement  << endl;






    return 0;
}