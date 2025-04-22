#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool isPossible(vector<int> &stalls, int k, int mid){
    int cowCount = 1;
    int lastPos = stalls[0];

    for(int i = 0; i < stalls.size(); i++){
        if(stalls[i]-lastPos >= mid){
            cowCount ++;
            if(cowCount == k){
                return true;
            }
            lastPos = stalls[i];
        }
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k){
    sort(stalls.begin(), stalls.end());
    int s = 0;
    int maxi = -1;

    for(int i = 0; i < stalls.size(); i++){
        maxi = max(maxi, stalls[i]);
    }
    int e = maxi;
    int ans = -1;
    
    while(s<=e){
        int mid = s + (e-s)/2;
        if(isPossible(stalls, k, mid)){
            ans = mid;
            s = mid + 1;
        }else{
            e = mid - 1;
        }
    }
    return ans;
}

int main() {
    vector<int> stalls;
    int size;
    int cows;

    cout<<"Enter the size of array: ";
    cin>>size;

    for(int i=0; i<size; i++){
        int temp;
        cin>> temp;
        stalls.push_back(temp);

    }

    cout<<"Array is ";
    for(int num : stalls){
        cout<< num << " ";
    }
    cout<<endl;
    cout<<"Enter the number of cow: ";
    cin>>cows;

    cout<<"There are "<<cows<<" cows";
    cout<<endl;

    int result = aggressiveCows(stalls, cows);
    cout<<"The maximum distance between cows is "<<result;



    return 0;
}