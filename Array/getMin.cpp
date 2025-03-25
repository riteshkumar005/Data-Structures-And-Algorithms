#include <iostream>
using namespace std;


int getMin(int nums[], int n){
    int min = nums[0];
    for(int i = 1; i < n; i++){
        if(min > nums[i]){
            min = nums[i];
        }
    }
    return min;

}

int main() {
    int nums[5];

    cout << "Enter 5 integers: " << endl;
    for(int i =0; i<5; i++){
        cin >> nums[i];
    };
    
    cout << "Original array: ";
    for(int num : nums ){
        cout << num <<" ";
    }
    cout << endl;
    

    int ans = getMin(nums, 5 );

    cout <<"Minimum number of elements is "<< ans;

    return 0;
}