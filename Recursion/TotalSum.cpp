#include <iostream>

using namespace std;

int getSum(int *arr, int size){
    if(size == 0) return   0;

    if(size==1){
        return arr[0];
    }

    int remainingPart=getSum(arr+1, size-1);
    int sum = arr[0]+remainingPart;


    return sum;

}

int main(){

    int arr[] = {2, 4, 6, 9, 12};  // Correct array with 5 elements
    int size = sizeof(arr) / sizeof(arr[0]);
    
    cout<<"Sum of the arr is "<<getSum(arr, size);


    return 0;

}