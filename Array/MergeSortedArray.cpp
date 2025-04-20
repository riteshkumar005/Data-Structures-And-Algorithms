#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
    for(int i = 0; i < m; i++){
        
        nums1.pop_back();
    }
    for(int i =0; i < nums2.size(); i++){
        nums1.push_back(nums2[i]);
    }
    sort(nums1.begin(), nums1.end());

    for(int num : nums1){
        cout << num << " ";
    }
}
int main() {
    vector<int> nums1, nums2;
    int size1,size2, key1, key2;

    cout << "Enter the number of elements in first of the vector: ";
    cin >> size1;

    cout << "Enter the elements: ";
    for (int i = 0; i < size1; i++) {
       
        int temp;
        cin >> temp;
        nums1.push_back(temp);  
    }

    cout<<"Enter no of element you want to merge: ";
    cin >> key1;

    cout << "Enter the number of elements in second of the vector: ";
    cin >> size2;

    cout << "Enter the elements: ";
    for (int i = 0; i < size2; i++) {
       
        int temp;
        cin >> temp;
        nums2.push_back(temp);  
    }
    cout<<"Enter no of element you want to merge: ";
    cin >> key2;

    cout << " First Original array: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    cout << " Second Original array: ";
    for (int num : nums2) {
        cout << num << " ";
    }
    cout << endl;

    merge(nums1, key1,  nums2, key2);

    
    return 0;
}