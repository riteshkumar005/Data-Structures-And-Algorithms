#include <iostream>
#include <string>

using namespace std;
bool checkEqual(int count1[26], int count2[26]){
    for(int i = 0; i < 26; i++){
        if(count1[26] != count2[26]) return 0;
    }

    return 1;
}

bool checkInclusion(string str1, string str2){
    //character count array
    int count1[26] = {0};

    for(int i = 0; i < str1.length(); i++){
        int index = str1[i] - 'a';
        count1[index]++;
    }

    //traves str2 string in window of size str1 length and compare

    int i = 0;
    int windowSize = str1.length();
    int count2[26] = {0};

    //runing for first window

    while(i < windowSize && i < str2.length() ){
        int index = str2[i] - 'a';
        count2[index] ++;
        i++;
    }

    if(checkEqual(count1, count2)) return 1;

    //aage window process karo
    while( i < str2.length()) {
        char  newChar = str2[i];
        int index = newChar - 'a';
        count2[index]++;
        
        char oldChar = str2[i - windowSize];
        index = oldChar - 'a';
        count2[index] --;
        
        i++;

        if(checkEqual(count1, count2)) return 1;
    }

    return 0;

   
}

int main() {
    string str1, str2;
    cout<<"Enter string str1: ";
    cin >> str1;
    cout<<"Enter string str2: ";
    cin >> str2;

    cout<<(checkInclusion(str1, str2) ? true : false);
    



    return 0;
}