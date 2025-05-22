#include <iostream>
#include <string>

using namespace std;

void reverseString(string str ){
    int low = 0, high = str.length()-1;

    while(low < high){
        char temp = str[low];
        str[low] =  str[high];
        str[high] = temp;
        
        low ++;
        high --;

    }

    cout<<"Reverse String is "<<str;
}

int main() {
    string str;
    cout <<"Enter string: ";
    cin >> str;

    reverseString(str);
    


    return 0;
}