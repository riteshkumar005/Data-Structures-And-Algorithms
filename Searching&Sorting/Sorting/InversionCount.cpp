#include <iostream>

using namespace std;

int inversionCount(int arr[], int n){

    int invCount=0;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]>arr[j]){
                invCount++;
            }
        }
    }

    return invCount;
}


int main(){
    int arr[20];
    cout<<"Enter the size of array: ";
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<"How far the array being sorted: "<<inversionCount(arr, n);



    return 0;
}