#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for(int i=0; i<nums.size(); i++){
        for(int j=i+1; j< nums.size();j++){
            if(nums[i] == nums[j]){
                return nums[i];

            }
        }
    }
    return -1;
}
int main(){
    vector<int> arr;
    int size;
    cout << "Enter the number of elements of the array: ";
    cin >> size;
    for(int i=0; i<size; i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    cout <<"Array is: ";
    for(int num: arr){
        cout << num << " ";
    }
    cout << endl;

    int num = findDuplicate(arr);
    cout << "Duplicate: " << num << endl;



    return 0;
}