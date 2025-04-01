#include <iostream>
#include <vector>

using namespace std;


void sortZeroOneAndTwo(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() -1;

    while(mid <= high) {
        if(nums[mid] == 0 ){
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if(nums[mid] == 1){
            mid++;
        }
        else if(nums[mid] == 2){
            swap(nums[mid], nums[high]);
            high--;
        }
    }

    cout << "Array after sorting is ";
    for(int num : nums){
        cout << num << " ";
    }
    cout << endl;
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

    sortZeroOneAndTwo(nums);




    return 0;
}