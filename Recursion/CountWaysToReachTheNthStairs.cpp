#include <iostream>

using namespace std;

int countDistinctWayToClimbStair(long long nStairs){
    if(nStairs<0) return 0;

    if(nStairs==0) return 1;

    int ans = countDistinctWayToClimbStair(nStairs-1)+countDistinctWayToClimbStair(nStairs-2);

    return ans;
}

int main(){
    cout<<"Enter the number of stairs:"<<endl;
    int n;
    cin>>n;
    int ans=countDistinctWayToClimbStair(n);

    cout<<"Number of way to climb stair  "<<n<<" is  "<<ans;



    return 0;
}