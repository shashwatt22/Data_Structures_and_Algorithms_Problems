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
    void insertAtBeginning(int val) {
        Node* n = new Node(val);
        if (!head)
            head = n;
        else {
            n->next = head;
            head->prev = n;
            head = n;
        }
        cout << "Inserted " << val << " at beginning.\n";
    }
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
        cout << "Inserted " << val << " at end.\n";
    }
    void insertBefore(int key, int val) {
        if (!head) return;
        Node* temp = head;
        while (temp && temp->data != key)
            temp = temp->next;
        if (!temp) {
            cout << "Node " << key << " not found.\n";
            return;
        }
        Node* n = new Node(val);
        n->next = temp;
        n->prev = temp->prev;
        if (temp->prev)
            temp->prev->next = n;
        else
            head = n;
        temp->prev = n;
        cout << "Inserted " << val << " before " << key << ".\n";
    }
    void insertAfter(int key, int val) {
        Node* temp = head;
        while (temp && temp->data != key)
            temp = temp->next;
        if (!temp) {
            cout << "Node " << key << " not found.\n";
            return;
        }
        Node* n = new Node(val);
        n->next = temp->next;
        n->prev = temp;
        if (temp->next)
            temp->next->prev = n;
        temp->next = n;
        cout << "Inserted " << val << " after " << key << ".\n";
    }
    void deleteNode(int key) {
        if (!head) return;
        Node* temp = head;
        while (temp && temp->data != key)
            temp = temp->next;
        if (!temp) {
            cout << "Node not found.\n";
            return;
        }
        if (temp->prev)
            temp->prev->next = temp->next;
        else
            head = temp->next;
        if (temp->next)
            temp->next->prev = temp->prev;
        delete temp;
        cout << "Deleted node " << key << ".\n";
    }
    bool search(int key) {
        Node* temp = head;
        while (temp) {
            if (temp->data == key)
                return true;
            temp = temp->next;
        }
        return false;
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
};
class CircularLinkedList {
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(NULL) {}
    };
    Node* head;

public:
    CircularLinkedList() : head(NULL) {}
    void insertAtBeginning(int val) {
        Node* n = new Node(val);
        if (!head) {
            head = n;
            n->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = n;
            n->next = head;
            head = n;
        }
        cout << "Inserted " << val << " at beginning.\n";
    }
    void insertAtEnd(int val) {
        Node* n = new Node(val);
        if (!head) {
            head = n;
            n->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = n;
            n->next = head;
        }
        cout << "Inserted " << val << " at end.\n";
    }
    void insertAfter(int key, int val) {
        if (!head) return;
        Node* temp = head;
        do {
            if (temp->data == key) {
                Node* n = new Node(val);
                n->next = temp->next;
                temp->next = n;
                cout << "Inserted " << val << " after " << key << ".\n";
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node " << key << " not found.\n";
    }
    void deleteNode(int key) {
        if (!head) return;
        Node *curr = head, *prev = NULL;
        do {
            if (curr->data == key) {
                if (curr == head && curr->next == head) {
                    head = NULL;
                    delete curr;
                    cout << "Deleted last remaining node.\n";
                    return;
                }
                if (curr == head) {
                    Node* temp = head;
                    while (temp->next != head)
                        temp = temp->next;
                    head = head->next;
                    temp->next = head;
                } else
                    prev->next = curr->next;

                delete curr;
                cout << "Deleted node " << key << ".\n";
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);
        cout << "Node not found.\n";
    }
    bool search(int key) {
        if (!head) return false;
        Node* temp = head;
        do {
            if (temp->data == key)
                return true;
            temp = temp->next;
        } while (temp != head);
        return false;
    }
    void display() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};
int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;
    int choice, val, key, type;

    while (true) {
        cout << "\n==== MENU ====\n";
        cout << "1. Insert Node\n";
        cout << "2. Delete Node\n";
        cout << "3. Search Node\n";
        cout << "4. Display Lists\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0) break;

        cout << "Select List Type (1 = Doubly, 2 = Circular): ";
        cin >> type;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                cout << "1.First  2.Last  3.After Node  4.Before Node: ";
                int opt;
                cin >> opt;
                if (type == 1) {
                    if (opt == 1) dll.insertAtBeginning(val);
                    else if (opt == 2) dll.insertAtEnd(val);
                    else if (opt == 3) {
                        cout << "After which node? ";
                        cin >> key;
                        dll.insertAfter(key, val);
                    } else if (opt == 4) {
                        cout << "Before which node? ";
                        cin >> key;
                        dll.insertBefore(key, val);
                    }
                } else {
                    if (opt == 1) cll.insertAtBeginning(val);
                    else if (opt == 2) cll.insertAtEnd(val);
                    else if (opt == 3) {
                        cout << "After which node? ";
                        cin >> key;
                        cll.insertAfter(key, val);
                    }
                }
                break;

            case 2:
                cout << "Enter node value to delete: ";
                cin >> key;
                if (type == 1)
                    dll.deleteNode(key);
                else
                    cll.deleteNode(key);
                break;

            case 3:
                cout << "Enter value to search: ";
                cin >> key;
                if (type == 1)
                    cout << (dll.search(key) ? "Found\n" : "Not Found\n");
                else
                    cout << (cll.search(key) ? "Found\n" : "Not Found\n");
                break;

            case 4:
                cout << "\n-- Doubly Linked List --\n";
                dll.display();
                cout << "-- Circular Linked List --\n";
                cll.display();
                break;

            default:
                cout << "Invalid choice.\n";
        }
    }

    return 0;
}
