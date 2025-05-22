#include <iostream>
#include <string>

using namespace std;


void removeOccurence(string &str, string substring){

    while(str.length() != 0 && str.find(substring) < str.length()){
        str.erase(str.find(substring), substring.length());
    }

}

int main() {
    cout <<"String is: ";
    string str, substring;

    getline(cin, str);
    cout<<"Enter substring: ";
    cin >> substring;

    removeOccurence(str,  substring);

    cout << "After remove all occurence "<<substring << " final string is "<< str;



    return 0;
}