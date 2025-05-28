#include <iostream>
#include <vector>
using namespace std;

// wavePrint function using vector of vectors
vector<int> wavePrint(const vector<vector<int>>& arr, int nRows, int mCols) {
    vector<int> ans;

    for (int col = 0; col < mCols; col++) {
        if (col & 1) {
            for (int row = nRows - 1; row >= 0; row--) {
                ans.push_back(arr[row][col]);
            }
        } else {
            for (int row = 0; row < nRows; row++) {
                ans.push_back(arr[row][col]);
            }
        }
    }

    return ans;
}

int main() {
    int n, m;
    cout << "Enter number of rows and columns: ";
    cin >> n >> m;

    // Declare a 2D vector
    vector<vector<int>> arr(n, vector<int>(m));

    // Take input
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    // Get wave print
    vector<int> ans = wavePrint(arr, n, m);

    // Output
    cout << "Wave print:\n";
    for (int val : ans) {
        cout << val << " ";
    }

    return 0;
}
