#include <iostream>

using namespace std;

bool checkPalindrome(string str, int low, int high){

    if(low>high) return true;

    if(str[low] != str[high]){
        return false;
    }else{
        return checkPalindrome(str, low++, high--);
    }
}

int main(){
    cout<<"Enter the string: ";
    string  str;
    cin>>str;
    cout<<"String is palindrome or not: "<<checkPalindrome(str,0,str.size()-1);
   

    return 0;
}