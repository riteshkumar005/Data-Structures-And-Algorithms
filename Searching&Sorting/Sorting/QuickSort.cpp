#include <iostream>

using namespace std;

int partition(int arr[], int low, int high){
    int pivot=arr[low];

    int cnt=0;
    for(int i=low+1; i<=high; i++){
        if(arr[i]<=pivot){
            cnt++;
        }
    }

    //place pivote at right position
    int pivotIndex=low+cnt;
    swap(arr[pivotIndex], arr[low]);

    //left and right wala part
    int i=low, j=high;
    while(i<pivotIndex && j>pivotIndex){
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }

        while(i<pivotIndex && j>pivotIndex){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }


    }
    return pivotIndex;
}
void quickSort(int arr[], int low, int high){
    //base case
    if(low >= high) return;

    //partition karenge
    int p = partition(arr, low, high);

    //left part sort karenge
    quickSort(arr, low, p-1);

    //right part sort karenge
    quickSort(arr, p+1, high);
}
int main(){
    int arr[20];
    cout<<"Enter the number of array: ";
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    quickSort(arr, 0, n-1);

    cout<<"After sorting array is  ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }


    return 0;
}