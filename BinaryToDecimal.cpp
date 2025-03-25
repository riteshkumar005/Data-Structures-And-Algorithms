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
    cout <<"Enter binary number"<<endl;
    cin >> num;
    int ans = 0;
    int i = 0;

    while(num != 0){
       
        // int bit = num & 1;
        int digit = num % 10;
        if(digit == 1){
            ans = (digit * pow(2, i)) + ans;
        };
        
        num =  num/10;
        i++;
    };

    cout <<"Decimal number is: "<< ans;

     

    return 0;
}