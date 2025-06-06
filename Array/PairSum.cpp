#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void pairSum(vector<int> arr, int s) {
    vector<vector<int>> ans;  // Corrected type

    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[i] + arr[j] == s) {
                vector<int> temp = {min(arr[i], arr[j]), max(arr[i], arr[j])};
                ans.push_back(temp);
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
    int size, s;
    cout << "Enter the number of elements in the array: ";
    cin >> size;
    vector<int> arr(size);

    cout << "Enter the elements: ";
    for (int i = 0; i < size; i++) {
        // int temp;
        // cin >> temp;
        // arr.push_back(temp);
        cin>>arr[i];
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
