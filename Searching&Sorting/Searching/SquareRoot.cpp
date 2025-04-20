#include <iostream>
#include <vector>
using namespace std;



long long int binarySearch(int n){
    int low = 0, high = n;
    
    long long int ans = -1;
    while(low <= high){
        long long int mid = low + (high - low)/2;
        long long int square = mid*mid;

        if(square == n) return mid;

        if( square < n){
            ans = mid;
            low = mid + 1;
        }else{
            high = mid - 1;   
        }
    }
    return ans;
}

double morePrecision(int n, int precision, int tempSol){
    double factor = 1;
    double ans = tempSol;

    for(int i=0; i < precision; i++){
        factor = factor/10;
        for(double j = ans; j*j < n; j = j + factor){
            ans = j;
        }
    }

    return ans;
}


int main() {
    int n;
    cout<<"Enter the number: ";

    cin >> n;
    int tempSol = binarySearch(n);
    cout <<"Square root of number "<< n <<" is "<<morePrecision(n, 3, tempSol);


    return 0;
}