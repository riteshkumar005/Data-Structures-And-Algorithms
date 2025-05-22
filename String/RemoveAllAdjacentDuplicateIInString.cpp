#include <iostream>
#include <string>

using namespace std;

string removeAdjacentDuplicate(string &str){
   
    int i = 0;
    while (i < str.length() - 1) {
        if (str[i] == str[i + 1]) {
            str.erase(i, 2); // remove the adjacent pair
            if (i != 0) i--; // step back to check for new pairs
        } else {
            i++;
        }
    }
    return str;
   
}


int main() {
    string str;
    cout<<"Enter string : ";
    cin >> str;
   
    cout<<"After remove all adjacent duplicate in string "<< removeAdjacentDuplicate(str);
    




    return 0;
}