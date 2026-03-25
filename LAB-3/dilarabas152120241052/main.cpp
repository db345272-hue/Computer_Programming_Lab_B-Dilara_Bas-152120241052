#include <iostream>
#include <string>

using namespace std;

struct Page{
    string url;
    string title;
    int accessTime[3];
    Page *next;
    Page *prev;
};
Page* head=nullptr;
Page* current=nullptr;

void visit(string u, string t, int h, int m, int s) {
    Page* newPage = new Page();
    newPage->url = u;
    newPage->title = t;
    newPage->accessTime[0]=h;
    newPage->accessTime[1]=m;
    newPage->accessTime[2]=s;
    newPage->next=nullptr;
    newPage->prev=nullptr;

    if(head==nullptr){
        head=newPage;
        current=newPage;
    }else{
        Page* temp=head;
        while (temp->next!=nullptr) {
            temp=temp->next;
        }
        temp->next=newPage;
        newPage->prev=temp;
        current=newPage;
    }
    cout << "Ziyaret edildi: " << t << endl;
}


void goBack(){
    if(current!=nullptr && current->prev != nullptr){
        current=current->prev;
        cout << "Geri gidildi. Su an: " << current->title << endl;
    }else{
        cout << "Geri gidecek sayfa yok!" << endl;
    }
}

void goForward(){
    if(current!= nullptr && current->next!=nullptr) {
        current=current->next;
        cout << "Ileri gidildi. Su an: " << current->title << endl;
    }else{
        cout << "Ileri gidecek sayfa yok!" << endl;
    }
}


void deleteCurrent(){
    if(current == nullptr) return;

    Page* toDelete = current;

    if(toDelete->prev != nullptr)
        toDelete->prev->next = toDelete->next;
    else
        head = toDelete->next;

    if(toDelete->next != nullptr)
        toDelete->next->prev = toDelete->prev;


    if(toDelete->prev != nullptr)
        current = toDelete->prev;
    else
        current = toDelete->next;

    delete toDelete;
    cout << "Sayfa gecmisten silindi." << endl;
}


void displayHistory(){
    cout << "\n--- GECMIS LISTESI ---" << endl;
    Page* temp = head;
    while(temp != nullptr) {
        if(temp == current) cout << ">>> ";

        cout << "[" << temp->title << " - " << temp->url << "] Saat: ";


        for(int i = 0; i < 3; i++) {
            cout << temp->accessTime[i] << (i < 2 ? ":" : "");
        }

        if(temp == current)cout << " (SU AN BURADASINIZ)";
        cout << endl;
        temp = temp->next;
    }
    cout << "----------------------\n" << endl;
}


void clearMemory(){
    Page* temp = head;
    while(temp != nullptr){
        Page* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
    head=nullptr;
    current=nullptr;
    cout << "Bellek temizlendi. Cikis yapiliyor..." << endl;
}

int main(){
    visit("google.com", "Google", 10, 30, 0);
    visit("github.com", "GitHub", 10, 35, 12);
    visit("stackoverflow.com", "Stack Overflow", 10, 40, 5);

    displayHistory();

    goBack();
    deleteCurrent();

    displayHistory();

    clearMemory();
    return 0;
}
