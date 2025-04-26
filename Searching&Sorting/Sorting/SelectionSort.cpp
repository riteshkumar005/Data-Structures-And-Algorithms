#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void selectionSort(vector<int>& nums, int n){
    for(int i = 0; i < n; i++){
        int minIndex = i;
        for(int j = i+1; j < n; j++){
            if(nums[j] < nums[minIndex]){
                minIndex = j;
            }

        }
        swap(nums[minIndex], nums[i]);
    }
}

int main(){
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

    selectionSort(nums, size);
    cout<<"After the selection sort Array is:";
    for(int num: nums){
        cout<<num<<" ";
    }



    return 0;
}