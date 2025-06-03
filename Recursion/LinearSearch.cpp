#include <iostream>

using namespace std;

bool linearSearch(int arr[], int size, int k){
    if(size==0) return false;

    if(arr[0]==k){
        return true;
    } 
    else{
        bool remainingPart=linearSearch(arr+1, size-1, k);
        return remainingPart;
    }
}

int main(){
    int arr[20];
    int n, k;

    cout<<"Enter the length of arr: ";
    cin>>n;
    for(int i=0; i<n; i++){

        cin>>arr[i];
    }
    cout<<"What element you search: ";
    cin>>k;
    cout<<"Element found in array is  "<<linearSearch(arr, n, k);

}