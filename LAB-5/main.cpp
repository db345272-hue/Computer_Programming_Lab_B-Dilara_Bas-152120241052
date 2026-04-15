#include <iostream>

using namespace std;


struct Node{
    int data;
    Node* next;
};


struct Stack{
    Node* top=nullptr;

    void push(int val){
        Node* newNode=new Node{val, top};
        top =newNode;
    }

    int pop(){
        if(isEmpty())
        return -1;
        int val = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return val;
    }

    bool isEmpty(){
        return top == nullptr;
        }

    void printStack(){
        Node* curr=top;
        while(curr){
            cout <<curr->data<<" ";
            curr = curr->next;
        }
        cout << endl;
    }
};


struct Queue{
    Node* front=nullptr;
    Node* rear=nullptr;

    void enqueue(int val){
        Node* newNode = new Node{val, nullptr};
        if(rear == nullptr){
            front= rear= newNode;
            return;
        }
        rear->next=newNode;
        rear = newNode;
    }

    int dequeue(){
        if (isEmpty())return -1;
        int val = front->data;
        Node* temp = front;
        front = front->next;
        if(front == nullptr)rear = nullptr;
        delete temp;
        return val;
    }

    bool isEmpty(){return front == nullptr;}
};


void transferStack(Stack* source,Stack* destination){
    Queue tempQueue;

    while(!source->isEmpty()){
        tempQueue.enqueue(source->pop());
    }

    while(!tempQueue.isEmpty()){
        destination->push(tempQueue.dequeue());
    }
}

int main(){
    Stack stackA, stackB;
    int input;

    cout << "Enter 5 integers to push into stackA:"<<endl;
    for(int i = 0; i < 5; i++){
        cout<<"Element"<<i + 1<< ": ";
        cin>>input;
        stackA.push(input);
    }
    cout<<"\nContents of stackA before transfer (Top to Bottom):";
    stackA.printStack();

    cout<<"Transferring stackA to stackB..."<<endl;
    transferStack(&stackA, &stackB);

    cout<<"Contents of stackB after transfer (Top to Bottom):";
    stackB.printStack();

    return 0;
}
