#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next;
};

void traverse(struct Node *temp);
int findMax(struct Node *temp);

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

  cout << "Nilai terbesar adalah : " << findMax(node1) << endl;

  cin.get();
  return 0;
}

void traverse(struct Node *temp) {
  int i = 1;
  while (temp != NULL) {
    cout << "Data ke " << i << " : ";
    cout << temp->data;
    temp = temp->next;
    cout << endl;
    i++;
  }
}

int findMax(struct Node *temp) {
  if (temp == NULL) {
    cout << "Linked list kosong." << endl;
    return -1; // nilai default jika kosong
  }

  int maxVal = temp->data;
  while (temp != NULL) {
    if (temp->data > maxVal) {
      maxVal = temp->data;
    }
    temp = temp->next;
  }
  return maxVal;
}

