#include <iostream>
#include <vector>

using namespace std;


int peakIndexInMountainArray(vector<int>& arr){
    int start = 0, end = arr.size()-1;

    int mid = start + (end - start)/2;

    while(start < end){
        if(arr[mid] < arr[mid + 1]){
            start = mid + 1;
        }
        else if(arr[mid] > arr[mid + 1]){
            end = mid;
        }

        mid = start + (end - start)/2;

    
    }

    return start;

}
int main() {
    vector<int> nums;
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    cout <<"Enter the number of elements (mountain array): ";
    for(int i = 0; i < size; i++) {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }

    int PeakIndex = peakIndexInMountainArray(nums);
    cout << "Peak index: " << PeakIndex << endl;

    


    return 0;
}