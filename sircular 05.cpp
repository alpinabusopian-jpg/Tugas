#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};

void traverse(Node *head);
void insertAtEnd(Node *&head, int value);

int main() {
    Node *node1 = new Node;
    Node *node2 = new Node;
    Node *node3 = new Node;

    node1->data = 10;
    node1->next = node2;
    node1->prev = node3;

    node2->data = 20;
    node2->next = node3;
    node2->prev = node1;

    node3->data = 30;
    node3->next = node1;
    node3->prev = node2;

    cout << "Data linked list awal : " << endl;
    traverse(node1);

    int tambahan;
    cout << "\nMasukkan data yang ditambahkan di akhir: ";
    cin >> tambahan;

    insertAtEnd(node1, tambahan);

    cout << "\nData setelah ditambah di akhir:" << endl;
    traverse(node1);

    cin.get();
    return 0;
}

void traverse(Node *head) {
    if (head == NULL) return;
    Node *temp = head;
    do {
        cout << temp->data << " <-> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(kembali ke awal)" << endl;
}

void insertAtEnd(Node *&head, int value) {
    Node *newNode = new Node;
    newNode->data = value;

    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        return;
    }

    // Node terakhir saat ini
    Node *tail = head->prev; 
    
    // Mengatur pointer untuk node baru
    newNode->next = head;
    newNode->prev = tail;
    
    // Menghubungkan node terakhir lama dan head ke node baru
    tail->next = newNode;
    head->prev = newNode;
    
    // Head tidak bergeser, jadi newNode otomatis ada di akhir
}
