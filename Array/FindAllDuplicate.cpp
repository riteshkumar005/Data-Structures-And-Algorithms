#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findDuplicate(vector<int>& nums) {
    vector<int> duplicate;
    sort(nums.begin(), nums.end());
    for(int i=0; i<nums.size(); i++){
        for(int j=i+1; j< nums.size();j++){
            if(nums[i] == nums[j]){
                duplicate.push_back(nums[i]);
                
            }
        }
    }
    return duplicate;
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

    vector<int> nums = findDuplicate(arr);
    cout << "Duplicate: ";

    for(int num : nums){
        cout << num << " ";
        
    }
    
    return 0;
}