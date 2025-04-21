#include <iostream>
#include <vector>

using namespace std;

bool isPossible(vector<int>& arr, int n, int m, int mid){
    int StudentCount = 1;
    int PageSum = 0;

    for(int i = 0; i<n; i++){
        if(PageSum + arr[i] <= mid){
            PageSum += arr[i];
        }else{
            StudentCount ++;
            if(StudentCount > m || arr[i] > mid){
                return false;
            }
            PageSum = arr[i];
        
        }

    }
    return true;
}

int allocateBooks(vector<int> arr, int m, int n){
    int low = 0, sum = 0;

    for(int i = 0; i < n; i++){
        sum += arr[i];
    }

    int high = sum, ans = -1;

    while(low <= high){
        int mid = low + (high - low)/2;
        if(isPossible(arr, n, m, mid)){
            ans = mid;
            high = mid - 1;
        }else {
            low = mid + 1;
        }
    }
    return ans;

}


int main() {
    vector<int> arr;
    int book;
    int student;

    cout<<"Enter the no. of Book: ";
    cin >> book;
    for(int i =0; i < book; i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    for(int num : arr){
        cout<< num<<" ";
    }
    cout<<endl;

    cout<<"Enter the number of student: ";
    cin>>student;

    int ans = allocateBooks(arr, student, book);

    cout<<"Allocate book is "<< ans ;


    return 0;
}