#include <iostream>
using namespace std;

class CircularQueue {
public:
    int* arr;
    int qfront;
    int rear;
    int size;

    CircularQueue(int size) {
        this->size = size;
        arr = new int[size];
        qfront = -1;
        rear = -1;
    }

    bool enqueue(int value) {
        // Check if queue is full
        if ((qfront == 0 && rear == size - 1) || (rear + 1) % size == qfront) {
            cout << "Queue is full" << endl;
            return false;
        }

        // First element to be inserted
        if (qfront == -1) {
            qfront = rear = 0;
        } 
        else if (rear == size - 1 && qfront != 0) {
            rear = 0;
        } 
        else {
            rear = (rear + 1) % size;
        }

        arr[rear] = value;
        return true;
    }

    int dequeue() {
        if (qfront == -1) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        int ans = arr[qfront];
        arr[qfront] = -1;

        if (qfront == rear) {
            qfront = rear = -1; // Queue is now empty
        } else {
            qfront = (qfront + 1) % size;
        }

        return ans;
    }
};

int main() {
    CircularQueue q(3);
    
    cout << q.enqueue(8) << endl;   // true
    cout << q.enqueue(12) << endl;  // true
    cout << q.enqueue(15) << endl;  // true
    cout << q.enqueue(18) << endl;  // false (queue full)

    cout << "Dequeue: " << q.dequeue() << endl; // 8
    cout << q.enqueue(20) << endl;              // true (wraps around)

    return 0;
}

