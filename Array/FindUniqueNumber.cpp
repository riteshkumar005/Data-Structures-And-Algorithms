#include <iostream>
#include <vector>
using namespace std;


void FindUniqueNumber(vector<int>& arr){

    int ans = 0;
    for(int i=0; i < arr.size(); i++){
        ans = ans ^ arr[i];
        
    };
    
    cout << "The unique number is: " << ans << endl;
 
}

int main(){
    vector<int> arr;
    int size;
    cout << "Enter the size of vector: ";
    cin >> size;

    for(int i = 0; i < size; i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    cout << "Original vector: ";
    for(int num : arr){
        cout << num << " ";
    }

    FindUniqueNumber(arr);



    return 0;
}