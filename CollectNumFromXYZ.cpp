#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    while(n!=0){
        int x = n%10;
        cout << x << " ";
        n = n/10;
    }


    return 0;
}