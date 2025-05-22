#include <iostream>
#include <vector>
#include <string>

using namespace std;

int stringCompress(vector<char>& ch) {
    int i = 0;
    int ansIndex = 0;
    int n = ch.size();

    while (i < n) {
        int j = i + 1;
        while (j < n && ch[i] == ch[j]) {
            j++;
        }

        ch[ansIndex++] = ch[i];

        int count = j - i;
        if (count > 1) {
            string cnt = to_string(count);
            for (char c : cnt) {
                ch[ansIndex++] = c;
            }
        }

        i = j;
    }

    return ansIndex;
}

int main() {
    string input;
    cout << "Enter string: ";
    cin >> input;

    vector<char> ch(input.begin(), input.end());

    int len = stringCompress(ch);

    cout << "After compression of string: ";
    for (int i = 0; i < len; ++i) {
        cout << ch[i];
    }
    cout << endl;

    return 0;
}
