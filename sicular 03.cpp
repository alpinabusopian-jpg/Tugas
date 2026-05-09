#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};

void traverse(Node *head);
int totalValue(Node *head);

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

    cout << "Data linked list adalah : " << endl;
    traverse(node1);

    cout << "Total nilai linked list adalah : " << totalValue(node1) << endl;

    cin.get();
    return 0;
}

void traverse(Node *head) {
    if (head == NULL) return;
    Node *temp = head;
    int i = 1;
    do {
        cout << "Data ke " << i << " : " << temp->data << endl;
        temp = temp->next;
        i++;
    } while (temp != head);
}

int totalValue(Node *head) {
    if (head == NULL) return 0;
    
    int total = 0;
    Node *temp = head;
    do {
        total += temp->data;
        temp = temp->next;
    } while (temp != head);
    
    return total;
}
