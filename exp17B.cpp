//subham
//entc B2
//23070123132
//experiment 17
#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* next;
};

void insert(Node*& head, int data) 
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void deleteNode(Node*& head, int key) 
{
    Node* temp = head;
    Node* prev = nullptr;
    if (temp != nullptr && temp->data == key) 
    {
        head = temp->next;
        delete temp;
        return;
    }
    while (temp != nullptr && temp->data != key) 
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == nullptr) return;
    prev->next = temp->next;        //update
    delete temp;
}

void display(Node* node) 
{
    while (node != nullptr) 
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() 
{
    Node* head = nullptr;
    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    cout << "Linked List: ";
    display(head);
    deleteNode(head, 20);
    cout << "After Deletion: ";
    display(head);
    return 0;
}