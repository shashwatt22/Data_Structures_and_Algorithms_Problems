#include <iostream>
using namespace std;

class DoublyLinkedList {
    struct Node {
        int data;
        Node* prev;
        Node* next;
        Node(int val) : data(val), prev(NULL), next(NULL) {}
    };
    Node* head;

public:
    DoublyLinkedList() : head(NULL) {}

    void insertAtEnd(int val) {
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

    int size() {
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }
