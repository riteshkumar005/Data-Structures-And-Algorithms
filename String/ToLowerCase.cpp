#include <iostream>
#include <string>

using namespace std;

char toLowerCase(char ch){
    char temp;p
    if(ch >= 'a' && ch <= 'z'){
        return ch;
    }else {
        temp = ch - 'A' + 'a';
       
        
    }
    return temp;

}

int main() {
    char ch;
    cout <<"Enter the text: ";
    cin>> ch;

    char result = toLowerCase(ch);
    cout << "Lower case is "<<result;
    


    return 0;
}