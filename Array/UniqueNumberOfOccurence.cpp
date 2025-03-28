#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void UniqueNumberOfOccurence(vector<int>& arr){
   
    vector<int> ans;

    int i = 0;
    sort(arr.begin(),arr.end());


    while(i < arr.size()){
        int count = 1;
        for(int j = i+1; j < arr.size(); j++){
            if(arr[i] == arr[j]){
                count++;
            }
        }
        ans.push_back(count);
        i = i + count;

    }

    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size()-1; i++){
        if(ans[i] == ans[i+1]){
            cout<<"false" ;
        }
    }

    cout<<"true";


}

int main() {
    vector<int> arr;
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    for(int i=0; i<size; i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    UniqueNumberOfOccurence(arr);

    
    

    return 0;
}