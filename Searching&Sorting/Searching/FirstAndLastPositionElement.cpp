#include <iostream>
#include <vector>

using namespace std;


int firstOccurence(vector<int>& nums, int key){
    int start = 0, end = nums.size()-1;

    int mid = start + (end - start)/2;

    int ans = -1;
    while(start < end){
        if(nums[mid] == key){
            ans = mid;
            end = mid - 1;
        }
        else if (nums[mid] >key){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }

        mid = start + (end - start)/2;

    }

    return ans;
}

int lastOccurence(vector<int>& nums, int key){
    int start = 0, end = nums.size()-1;

    int mid = start + (end - start)/2;

    int ans = -1;
    while(start < end){
        if(nums[mid] == key){
            ans = mid;
            start = mid + 1;
        }
        else if (nums[mid] >key){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }

        mid = start + (end - start)/2;

    }

    return ans;
}


int main() {
    vector<int> nums;
    int size;
    vector<int> ans;
    int key;
    cout<<"Enter the size of the array: ";
    cin >> size;

    cout<<"Enter a sorted Array"<<endl;
    for(int i = 0; i < size; i++){
        int temp;
        cin >> temp;
        nums.push_back(temp);

    }

    cout<<"Sorted Array: ";
    for(int num : nums){
        cout << num<<" ";
    }
    cout<<endl;

    cout<<"Enter the key you want to find first and last position: ";
    cin >> key;
    

 
    int firstIndex = firstOccurence(nums, key);
    int lastIndex = lastOccurence(nums, key);

    ans.push_back(firstIndex);
    ans.push_back(lastIndex);

    cout<<"First and last occurrence of "<<key<<" are at indices: ";
    for(int ind : ans){
        cout<<ind<<" ";
    }




    return 0;
}