#include <iostream>
using namespace std;

int main(){
    int n;
    int a = 0;
    int b = 1;
    cout <<"Taken a number for fibonacci ";
    cin >> n;

    cout << a << " "<< b<<" " ;
   
    for(int i = 1; i < n; i++){
        int NextNumber = a+b;
        cout <<NextNumber << " ";
        a = b;
        b = NextNumber;
    }
     


    return 0;
}