#include <iostream>

using namespace std;

void reverse(string &str, int low, int high){
    if(low>high) return;
    
    swap(str[low], str[high]);
    low++;
    high--;
    reverse(str, low, high);


}

int main(){
    cout<<"Enter the string: ";
    string  str;
    cin>>str;
    cout<<"Before String is  "<<str<<endl;
    reverse(str, 0, str.length()-1);

    cout<<"After String is  "<<str;




    return 0;
}