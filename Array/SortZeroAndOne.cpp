#include <iostream>
#include <vector>
using namespace std;


void sortZeroAndOne(vector<int>& nums) {
    int left = 0, right = nums.size()-1;

    while(left < right) {
        if(nums[left] == 0 && left < right)
        {
            left++;
        }
        else if(nums[right] == 1 && left < right)
        {
            right--;
        }
        else {
            swap(nums[left], nums[right]);
            left++;
            right--;
        } 
       
    }

    cout <<"Sorted Array is ";
    for(int num : nums){
        cout << num << " ";
    }




}

int main() {
    vector<int> nums;
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    for(int i = 0; i < size; i++) {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }

    cout << "Original Array is ";
    for(int num : nums){
        cout << num << " ";
    }
    cout << endl;

    sortZeroAndOne(nums);

    return 0;
}