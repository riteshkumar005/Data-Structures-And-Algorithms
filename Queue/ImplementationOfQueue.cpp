#include <iostream>
using namespace std;

class Queue{

    int* arr;
    int qfront;
    int rear;
    int size;
   
    //constructor
   public:
    Queue(int size){
        this->size=size;
        arr=new int[size];
        qfront=0;
        rear=0;

    }

    void enqueue(int data){
        if(rear == (size)){
            cout<<"Queue is full"<<endl;
            return ;
            
        }
        else
        {
            arr[rear]=data;
            rear++;
        }
    }

    int dequeue(){
        if(qfront==rear){
            return -1;
        }
        else{
            int ans=arr[qfront];
            arr[qfront]=-1;
            qfront++;

            if(qfront==rear){
                qfront=0;
                rear=0;
            }
            return ans;
        }
    }

    int front(){
        if(qfront==rear){
            return -1;
        }
        else{
            return arr[qfront];
        }
    }

    bool isEmpty(){
        if(qfront==rear){
            return true;
        }
        else{
            return false;
        }
    }
 
};


int main(){
    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    cout<<q.front()<<endl;
    q.dequeue();
    q.enqueue(6);
    
    


   
   

    return 0;
}
