#include <iostream>
using namespace std;

bool binarySearch(int *arr, int low, int high, int k ){
    int mid = low + (high-low)/2;
    if(low>high) return false;

    if(arr[mid]==k) return true;
    if(arr[mid]>k){
        return binarySearch(arr, 0, mid-1, k);
    }else{
        return binarySearch(arr, mid+1, high, k);
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
    cout<<"Element found is "<<binarySearch(arr, 0, n-1, k);

    return 0;
}