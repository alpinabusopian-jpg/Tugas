#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next;
};

void traverse(struct Node *temp);
void insertAtEnd(Node *&head, int value);

int main() {
  Node *node1 = NULL;
  Node *node2 = NULL;
  Node *node3 = NULL;

  node1 = new Node;
  node2 = new Node;
  node3 = new Node;

  node1->data = 10;
  node1->next = node2;

  node2->data = 20;
  node2->next = node3;

  node3->data = 30;
  node3->next = NULL;

  cout << "Data linked list adalah : " << endl;
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

void traverse(struct Node *temp) {
  while (temp != NULL) {
    cout << temp->data << " -> ";
    temp = temp->next;
  }
  cout << "NULL" << endl;
}

void insertAtEnd(Node *&head, int value) {
  Node *newNode = new Node;
  newNode->data = value;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
    return;
  }

  Node *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = newNode;
}

