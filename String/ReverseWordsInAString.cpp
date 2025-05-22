#include <iostream>
#include <string>

using namespace  std;

void reverseString(string &str, int start, int end){
    

    while(start < end){
        char temp = str[start];
        str[start] =  str[end];
        str[end] = temp;
        
        start ++;
        end --;

    }

    
}

void reverseWordsInString(string str){
    int start = 0;
    for(int i = 0; i <= str.length(); i++){
        if(i == str.length() || str[i] == ' '){
            reverseString(str, start, i-1);
            start = i + 1;

        }
    }

    cout<<"Reverse string in word is "<<str;

}
int main() {
    cout <<"String is: ";
    string str;
    getline(cin, str);

    reverseWordsInString(str);
    


    return 0;
}