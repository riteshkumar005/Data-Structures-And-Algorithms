#include <iostream>
using namespace std;

class Stack {
public:
    int *arr;
    int topIndex;  // renamed to avoid conflict
    int size;

    // Constructor
    Stack(int size) {
        this->size = size;
        arr = new int[size];
        topIndex = -1;
    }

    void push(int element) {
        if ((size - topIndex) > 1) {
            topIndex++;
            arr[topIndex] = element;
        } else {
            cout << "Stack overflow" << endl;
        }
    }

    void pop() {
        if (topIndex >= 0) {
            cout<<"Popped: "<<arr[topIndex];
            topIndex--;
            
        } else {
            cout << "Stack underflow" << endl;
            return ;
        }
    }

    int peek() {  // renamed from top() to peek()
        if (topIndex >= 0) {
            return arr[topIndex];
        } else {
            cout << "Stack empty" << endl;
            return -1;
        }
    }

    bool isEmpty() {
        return topIndex == -1;
    }
};

int main() {
    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout << "Top of stack: " << st.peek() << endl;

    st.pop();
    st.pop();
   
    cout << "Top after pop: " << st.peek() << endl;
    cout<< st.isEmpty()<<endl;

    return 0;
}
