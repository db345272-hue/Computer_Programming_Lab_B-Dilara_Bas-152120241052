#include <iostream>
#include <string>
#include <stack>
using namespace std;
struct Customer{
 string customerName;
 string currencyType;
 };


struct MoneyBundle{
    string serialNumber;
    string currencyType;
    int billCounts[3];
};
 struct Node{
     MoneyBundle data;
     Node* next;
 };
 struct MoneyStack{
  Node* top=nullptr;

  void push(MoneyBundle bundle){
      Node* newNode= new Node();
      newNode->data = bundle;
      newNode->next= top;
      top = newNode;
   }
   void pop(){
    if(top == nullptr){
        return;
    }
    Node* temp = top;
    top = top->next;
    delete temp;
    }
    void display(){
        cout << "\n--- KASADAKÝ PARA BALYALARI (STACK) ---" << endl;
        if(!top){ cout << "Kasa bos!" << endl; return; }
        Node* curr = top;
        while(curr){
            cout << "[" << curr->data.serialNumber << " | " << curr->data.currencyType << " | 100s:"
                 << curr->data.billCounts[0] << ", 50s:" << curr->data.billCounts[1] << ", 20s:" << curr->data.billCounts[2] << "]" << endl;
            curr=curr->next;
        }
    }
};
struct CustomerQueue{
    Customer queueArray[5];
    int front = -1;
    int rear = -1;
    int capacity = 5;

    bool isFull(){ return (rear + 1) % capacity == front; }
    bool isEmpty(){ return front == -1; }

    void enqueue(Customer c){
        if(isFull()){
            cout << "Hata: Kuyruk dolu, musteri alinmiyor!" << endl;
            return;
        }
        if(isEmpty())front = 0;
        rear = (rear + 1) % capacity;
        queueArray[rear] = c;
    }

    void dequeue(){
        if(isEmpty())return;
        if(front == rear){
            front = -1;
            rear = -1;
        }else{
            front = (front + 1) % capacity;
        }
    }

    void display(){
        cout << "\n--- BEKLEYEN MUSTERILER (QUEUE) ---" << endl;
        if(isEmpty()){ cout << "Kuyruk bos!" << endl; return; }
        int i = front;
        while(true){
            cout << "[" << queueArray[i].customerName << " - " << queueArray[i].currencyType << "]" << endl;
            if(i == rear)break;
            i= (i + 1) % capacity;
        }
    }
};


void processTransaction(CustomerQueue& q, MoneyStack& s){
    if(q.isEmpty()){
        cout << "Islem yapilacak musteri yok!" << endl;
        return;
    }
    if(s.top == nullptr){
        cout << "Kasa bos, islem gerceklestirilemiyor!" << endl;
        return;
    }

    cout << "\n>>> ISLEM YAPILIYOR..." << endl;
    cout << "Musteri: " << q.queueArray[q.front].customerName << " servisi aldi." << endl;
    cout << "Kullanilan Balya: " << s.top->data.serialNumber << endl;

    q.dequeue();
    s.pop();
}

int main(){
    MoneyStack kasa;
    CustomerQueue bankaSira;


    kasa.push({"SN001", "TL", {10, 5, 2}});
    kasa.push({"SN002", "USD", {20, 0, 0}});

    bankaSira.enqueue({"Ali", "Withdraw"});
    bankaSira.enqueue({"Ayse", "Deposit"});


    kasa.display();
    bankaSira.display();


    processTransaction(bankaSira, kasa);


    kasa.display();
    bankaSira.display();

    return 0;
}
