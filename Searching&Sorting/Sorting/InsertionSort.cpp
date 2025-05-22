#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void insertionSort(vector<int>& nums, int n){
    for(int i = 1; i < n; i++){
        int temp = nums[i];
        int j = i-1;
        for(j = i-1; j>=0; j--){
            if(nums[j] > temp){
                nums[j+1] = nums[j];
            }else{
                break;
            }
           
        }
        nums[j+1] = temp;

    }
   
}

int main() {
    vector<int> nums;
    int size;

    cout<<"Enter the size of array:";
    cin>>size;
    cout<<"Enter the Array:";
    for(int i = 0; i<size; i++){
        int temp;
        cin>> temp;
        nums.push_back(temp);
    }
    cout<<endl;
    cout<<"Array is:";

    for(int num: nums){
        cout<<num<<" ";
    }

    insertionSort(nums, size);
    cout<<endl;
    cout<<"After the insertion sort Array is:";
    for(int num: nums){
        cout<<num<<" ";
    }



    return 0;
}