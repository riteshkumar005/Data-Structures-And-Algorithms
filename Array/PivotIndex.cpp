#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int pivotIndex(vector<int>& nums) {
    int total = accumulate(nums.begin(), nums.end(), 0);
     int leftTotal = 0;

     for (int i = 0; i < nums.size(); i++) {
        cout << i << " ";
         int rightTotal = total - leftTotal - nums[i];
         if (rightTotal == leftTotal) {
             return i;
         }
         leftTotal += nums[i];
     }

     return -1;        
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

    int Index = pivotIndex(nums);
    cout << "Pivot index: " << Index  << endl;

    return 0;
}