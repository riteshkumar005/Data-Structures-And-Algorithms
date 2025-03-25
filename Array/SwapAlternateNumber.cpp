#include <iostream>
#include <vector>
using namespace std;


void SwapAlternateNumber(vector<int>& arr){

    for(int i=0; i < arr.size(); i+=2){
        swap(arr[i], arr[i+1]);
        

    };
    cout << "\nVector after swapping alternate numbers: ";
    for(int num : arr){
        cout << num << " ";
    }
 
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

    SwapAlternateNumber(arr);



    return 0;
}