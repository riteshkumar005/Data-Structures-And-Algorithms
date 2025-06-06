#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Declare functions before use
bool isSafe(int x, int y, int n, vector<vector<int>> &visited, vector<vector<int>> &m);
void solve(vector<vector<int>> &m, int n, vector<string> &ans, int x, int y, vector<vector<int>> &visited, string path);

vector<string> findPath(vector<vector<int>> &m, int n) {
    vector<string> ans;

    if (m[0][0] == 0) {
        return ans;
    }

    vector<vector<int>> visited(n, vector<int>(n, 0));
    string path = "";

    solve(m, n, ans, 0, 0, visited, path);

    sort(ans.begin(), ans.end());
    return ans;
}

void solve(vector<vector<int>> &m, int n, vector<string> &ans, int x, int y, vector<vector<int>> &visited, string path) {
    if (x == n - 1 && y == n - 1) {
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;

    // Down
    int newX = x + 1;
    int newY = y;
    if (isSafe(newX, newY, n, visited, m)) {
        path.push_back('D');
        solve(m, n, ans, newX, newY, visited, path);
        path.pop_back();
    }

    // Left
    newX = x;
    newY = y - 1;
    if (isSafe(newX, newY, n, visited, m)) {
        path.push_back('L');
        solve(m, n, ans, newX, newY, visited, path);
        path.pop_back();
    }

    // Right
    newX = x;
    newY = y + 1;
    if (isSafe(newX, newY, n, visited, m)) {
        path.push_back('R');
        solve(m, n, ans, newX, newY, visited, path);
        path.pop_back();
    }

    // Up
    newX = x - 1;
    newY = y;
    if (isSafe(newX, newY, n, visited, m)) {
        path.push_back('U');
        solve(m, n, ans, newX, newY, visited, path);
        path.pop_back();
    }

    visited[x][y] = 0;
}

bool isSafe(int x, int y, int n, vector<vector<int>> &visited, vector<vector<int>> &m) {
    return (x >= 0 && x < n && y >= 0 && y < n && visited[x][y] == 0 && m[x][y] == 1);
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));
    cout << "Enter the matrix (only 0s and 1s):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    vector<string> str = findPath(arr, n);

    if (str.empty()) {
        cout << "No path found.\n";
    } else {
        cout << "Paths:\n";
        for (const string &s : str) {
            cout << s << "\n";
        }
    }

    return 0;
}
