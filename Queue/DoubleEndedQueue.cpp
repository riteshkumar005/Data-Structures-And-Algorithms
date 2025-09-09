#include <iostream>
using namespace std;

class Deque {
public:
    int* arr;
    int qfront;
    int rear;
    int size;

    Deque(int size) {
        this->size = size;
        arr = new int[size];
        qfront = -1;
        rear = -1;
    }

    bool isFull() {
        return ((qfront == 0 && rear == size - 1) || (rear + 1) % size == qfront);
    }

    bool isEmpty() {
        return qfront == -1;
    }

    bool pushFront(int data) {
        if (isFull()) return false;

        if (isEmpty()) {
            qfront = rear = 0;
        } else if (qfront == 0) {
            qfront = size - 1;
        } else {
            qfront--;
        }

        arr[qfront] = data;
        return true;
    }

    bool pushRear(int data) {
        if (isFull()) return false;

        if (isEmpty()) {
            qfront = rear = 0;
        } else if (rear == size - 1) {
            rear = 0;
        } else {
            rear++;
        }

        arr[rear] = data;
        return true;
    }

    int popFront() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        int ans = arr[qfront];
        arr[qfront] = -1;

        if (qfront == rear) {
            qfront = rear = -1;
        } else if (qfront == size - 1) {
            qfront = 0;
        } else {
            qfront++;
        }

        return ans;
    }

    int popRear() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        int ans = arr[rear];
        arr[rear] = -1;

        if (qfront == rear) {
            qfront = rear = -1;
        } else if (rear == 0) {
            rear = size - 1;
        } else {
            rear--;
        }

        return ans;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[qfront];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return arr[rear];
    }
};

int main() {
    Deque dq(5);

    cout << dq.pushFront(10) << endl;  // 1
    dq.pushFront(20);
    dq.pushFront(30);
    dq.pushRear(5);
    dq.pushRear(3);  // This one should fail if deque is full

    cout << "Front: " << dq.getFront() << endl;  // 30
    cout << "Rear: " << dq.getRear() << endl;    // 5 or 3 based on insertion success
    cout << "Is Full: " << dq.isFull() << endl;  // 1 or 0
    cout << "Is Empty: " << dq.isEmpty() << endl;  // 0

    return 0;
}
