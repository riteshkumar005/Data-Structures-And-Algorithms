#include <iostream>

using namespace std;

void merge(int *arr, int low, int high){
    int mid = (low+high)/2;

    int len1 = mid-low+1;
    int len2 = high-mid;

    int *first = new int[len1];
    int *second = new int[len2];

    //copy value
    int mainArrayIndex = low;
    for(int i=0; i<len1; i++){
        first[i] = arr[mainArrayIndex++];
    }
    mainArrayIndex = mid+1;

    for(int i=0; i<len2; i++){
        second[i] = arr[mainArrayIndex++];
    }

    //merge 2 sorted array
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = low;

    while(index1<len1 && index2<len2){
        if(first[index1]<second[index2]){
            arr[mainArrayIndex++]=first[index1++];
        }else{
            arr[mainArrayIndex++]=second[index2++];
        }
    }

    while(index1<len1){
        arr[mainArrayIndex++]=first[index1++];
    }

    while(index2<len2){
        arr[mainArrayIndex++]=second[index2++];
    }

    delete []first;
    delete []second;
}

void mergeSort(int *arr, int low, int high){
    if(low>=high) return;

    int mid = (low+high)/2;

    //left part sort karenge
    mergeSort(arr, low, mid);

    //right part sort karenge
    mergeSort(arr, mid+1, high);

    //merge
    merge(arr, low, high);
    

}
int main(){
    int arr[5] = {2,5,1,6,9};
    int n = 5;

    mergeSort(arr, 0, n-1);
    cout<<"Sorted array  ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}