#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void pairSum(vector<int> arr, int s) {
    vector<vector<int>> ans;  

    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            for(int k = j+1; k < arr.size(); k++) {
                if (arr[i] + arr[j] + arr[k] == s) {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    ans.push_back(temp);
                }
            }
            
        }
    }

    sort(ans.begin(), ans.end());  // Sorting pairs for ordered output

    cout << "Pairs with given sum: " << endl;
    for (vector<int> pair : ans) {  // Corrected `Vector<int>` to `vector<int>`
        cout << pair[0] << " " << pair[1] << endl;
    }
}

int main() {
    vector<int> arr;
    int size, s;

    cout << "Enter the number of elements in the array: ";
    cin >> size;

    cout << "Enter the elements: ";
    for (int i = 0; i < size; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    cout << "Enter the target sum: ";
    cin >> s;

    cout << "Array is: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    pairSum(arr, s);

    return 0;
}
