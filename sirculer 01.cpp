#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};

void traverse(Node *head);

int main() {
    Node *node1 = new Node;
    Node *node2 = new Node;
    Node *node3 = new Node;

    // Mengisi data
    node1->data = 10;
    node2->data = 20;
    node3->data = 30;

    // Menghubungkan secara Circular Doubly
    node1->next = node2;
    node1->prev = node3; // Kembali ke belakang

    node2->next = node3;
    node2->prev = node1;

    node3->next = node1; // Kembali ke depan
    node3->prev = node2;

    cout << "Data linked list adalah : " << endl;
    traverse(node1);

    cin.get();
    return 0;
}

void traverse(Node *head) {
    if (head == NULL) return;
    
    Node *temp = head;
    int i = 1;
    // Menggunakan do-while karena temp == head di awal iterasi
    do {
        cout << "Data ke " << i << " : " << temp->data << endl;
        temp = temp->next;
        i++;
    } while (temp != head);
}
