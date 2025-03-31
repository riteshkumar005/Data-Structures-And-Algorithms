#include <iostream>
#include <vector>
using namespace std;


void ArrayIntersection(vector<int>& num1 , vector<int>& num2){
    vector<int> arrayInteraction;
    for(int i = 0; i < num1.size(); i++){
        int element = num1[i];
        for(int j = 0; j < num2.size(); j++){
            if(element == num2[j]){
                arrayInteraction.push_back(element);
                num2[j] = -1;
                break;

            }
           
            
        }

    }

    cout << "ArrayInteraction: ";
    for(int arr : arrayInteraction){
        cout << arr <<" ";
    }
   

}


int main(){
    vector<int> num1;
    vector<int> num2;
     
    int size;
    cout << "Enter the number of elements of the first array: ";
    cin >> size;
    for(int i=0; i<size; i++){
        int temp;
        cin >> temp;
        num1.push_back(temp);
    }

    cout << "Enter the number of elements of the second array: ";
    cin >> size;
    for(int i=0; i<size; i++){
        int temp;
        cin >> temp;
        num2.push_back(temp);
    }

    cout <<"First array is: ";
    for(int num: num1){
        cout << num << " ";
    }
    cout << endl;
    cout <<"Second  array is: ";
    for(int num: num2){
        cout << num << " ";
    }
    cout << endl;

   ArrayIntersection(num1, num2);


    return 0;
}