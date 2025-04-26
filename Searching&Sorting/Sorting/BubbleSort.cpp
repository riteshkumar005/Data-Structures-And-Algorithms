#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bubbleSort(vector<int>& nums, int n){
    for(int i = 1; i < n; i++){
        
        bool swapped = false;
        for(int j = 0; j < n-1; j++){
            if(nums[j] > nums[j+1]){
                swap(nums[j], nums[j+1]);
                swapped = true;
            }

        }
      if(swapped == false) break;
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

    bubbleSort(nums, size);
    cout<<endl;
    cout<<"After the selection sort Array is:";
    for(int num: nums){
        cout<<num<<" ";
    }



    return 0;
}