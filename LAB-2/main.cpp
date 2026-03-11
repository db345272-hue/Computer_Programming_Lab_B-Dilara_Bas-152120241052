#include <iostream>
#include <string>

using namespace std;


struct Node {
    string songTitle;
    Node* next;
};


void addSong(Node* &head, string title) {
    Node* newNode = new Node();
    newNode->songTitle = title;
    newNode->next = head;
    head = newNode;
    cout << "Added: \"" << title << "\" to the top of the playlist.\n";
}


void listSongs(Node* head) {
    if (head == NULL) {
        cout << "\nThe playlist is currently empty.\n";
        return;
    }

    cout << "\n--- Your Playlist ---\n";
    Node* temp = head;
    int count = 1;
    while (temp != NULL) {
        cout << count << ". " << temp->songTitle << endl;
        temp = temp->next;
        count++;
    }
}


void searchSong(Node* head, string title) {
    Node* temp = head;
    bool found = false;

    while (temp != NULL) {
        if (temp->songTitle == title) {
            found = true;
            break;
        }
        temp = temp->next;
    }

    if (found) {
        cout << "Song \"" << title << "\" was found in the playlist!\n";
    } else {
        cout << "Song \"" << title << "\" was not found.\n";
    }
}

int main() {
    Node* head = NULL;
    int choice;
    string title;

    do {
        cout << "\n--- Main Menu ---\n";
        cout << "1. Add Song (Prepend)\n";
        cout << "2. Search Song\n";
        cout << "3. List All Songs\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter song title: ";
                getline(cin, title);
                addSong(head, title);
                break;
            case 2:
                cout << "Enter song title to search: ";
                getline(cin, title);
                searchSong(head, title);
                break;
            case 3:
                listSongs(head);
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
