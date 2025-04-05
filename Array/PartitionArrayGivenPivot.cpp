#include <iostream>
#include <vector>

using namespace std;


vector<int> pivotArray(vector<int>& nums, int pivot) {
    vector<int> leftarray, rightarray;
    vector<int> ans;
    int count = 0;

    for(int num : nums){
        if(num < pivot){
            leftarray.push_back(num);
        }
        else if(num == pivot){
            count++;
        }
        else {
            rightarray.push_back(num);
        }
    }

    for(int i = 0; i < leftarray.size(); i++){
        ans.push_back(leftarray[i]);
    }

    for(int i = 0; i<count; i++){
        ans.push_back(pivot);
    }

    for(int i = 0; i < rightarray.size(); i++){
        ans.push_back(rightarray[i]);
    }

    return ans;
}


int main() {
    vector<int> nums;
    vector<int> rearrange_array;
    int size;
    int pivot;
    cout << "Enter the size of the array: ";
    cin >> size;
    cout <<"Enter the number of elements (Pivot in an array): ";
    for(int i = 0; i < size; i++) {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    
    cout << "Enter Pivot element: " << endl;
    cin >> pivot;
    cout << "Original array: ";
    for(int arr : nums) {
        cout << arr << " ";
    }
    cout << endl;
    
    cout << "Rearranged array: ";

    rearrange_array = pivotArray(nums, pivot);

    for(int arr : rearrange_array) {
        cout << arr << " ";
    }

    return 0;
}