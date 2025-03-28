#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void FindDuplicate(vector<int>& arr){
    vector<int> ans;
    int i = 0;
    
    sort(arr.begin(), arr.end());
    while(i < arr.size()){
        int count = 1;
        for(int j=i+1; j<arr.size(); j++){
            if(arr[i] == arr[j]){
                count++;
            }
        }
        ans.push_back(count);
        
        i = i + count;
    
    }
    for(int num : ans){
        cout<< num;
    }

    cout << "Duplicate elements are: ";
    sort(ans.begin(), ans.end());
    for(int j=0; j<ans.size(); j++){
        if(ans[j] > 1){
            cout << arr[i] << " ";
        }
    }
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

    FindDuplicate(arr);



    return 0;
}