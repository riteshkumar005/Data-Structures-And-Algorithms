#include <iostream>
#include <string>

using namespace std;

bool checkPalindrome(string str){
    int low = 0;
    int high = str.length() - 1;
    while(low < high){
        if(str[low] != str[high]){
            return 0;
        }else {
            low ++;
            high --;

        }
       
    }
    return 1;
}


int main() {
    string str;
    cout <<"Enter string: ";
    cin >> str;

    bool result = checkPalindrome(str);
    cout<<"String is "<<result<<" palindrome";


    return 0;
}