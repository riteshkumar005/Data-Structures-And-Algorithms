#include <iostream>
#include <cmath>
using namespace std;



//Decimal to binary
    
    // int n;
    // cin >> n;
    // while(n!=0){
    //     int x = n%2;
    //     cout << x <<" ";
    //     n = n/2;
    // }
int main(){
    int num;
    cout <<"Enter decimal number"<<endl;
    cin >> num;
    int ans = 0;
    int i = 0;

    while(num != 0){
       
        int bit = num & 1;
        ans = (bit * pow(10, i)) + ans;
       
       num =  num >> 1;
        i++;
    }
    cout <<"Binary number is: "<< ans;

     

    return 0;
}