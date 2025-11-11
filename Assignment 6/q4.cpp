#include <iostream>
using namespace std;

class DoublyLinkedList {
    struct Node {
        char data;
        Node* prev;
        Node* next;
        Node(char val) : data(val), prev(NULL), next(NULL) {}
    };
    Node* head;

public:
    DoublyLinkedList() : head(NULL) {}

    void insertAtEnd(char val) {
        Node* n = new Node(val);
        if (!head)
            head = n;
        else {
            Node* temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = n;
            n->prev = temp;
        }
    }

    void display() {
        Node* temp = head;
        cout << "Doubly Linked List: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
