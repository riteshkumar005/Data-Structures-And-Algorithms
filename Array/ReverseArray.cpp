#include <iostream>
#include <vector>

using namespace std;

void Reverse(vector<int>& nums) {
    int start = 0;
    int end = nums.size() - 1;
    while (start <= end) {
        swap(nums[start], nums[end]);
        start++;
        end--;
    }
}

int main() {
    vector<int> nums;
    int n;

    cout << "Enter the number of elements in the vector: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }

    cout << "Original array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl; 

    Reverse(nums);

    cout << "Reversed array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;  

    return 0;
}
