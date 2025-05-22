#include <iostream>
#include <string>

using namespace std;

void replaceSpace(string &str) {
    for(int i = 0; i < str.length(); i++){
        if(str[i] == ' '){
            str[i] = '@';
        }
    }
}
int main() {
    cout <<"String is: ";
    string str;
    getline(cin, str);

    replaceSpace(str);

    cout<< "After replace Space string is " << str;



    return 0;
}
