#include <iostream>

using namespace std;

void bubbleSort(int *arr, int n){
    //base case already sorted
    if(n==0 || n==1) return ;

    //1-case largest element ko end me rakh dena
    for(int i=0; i<n-1; i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    } 
    //Recursive call
    bubbleSort(arr, n-1);
}

int main(){
    int arr[20];
    int n;

    cout<<"Enter the length of arr: ";
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Before array:  ";
     for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    bubbleSort(arr, n);
    cout<<endl;
    cout<<"After sort the array"<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }


    return 0;
}