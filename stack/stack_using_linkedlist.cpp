#include <iostream>
using namespace std;

// Implementing Stack using Linked List

class node{
public:
    int data;
    node* next;

    node(int x) {
        data = x;
        next = NULL;
    }
};


class LinkedList{
public:
    bool is_empty(node* head) {
        return head == NULL;
    }

    node* insertAtHead(int d, node* &head) {
        if (head == NULL) {
            return head = new node(d);
        }
        node* new_head = new node(d);
        new_head->next = head;
        head = new_head;
        return head;
    }

    node* insertAtTail(int d, node* &head) {
        if (head == NULL) {
            return head = new node(d);
        }
        node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new node(d);
        return head;
    }

    node* deleteFromHead(node* head) {
        if (head == NULL) {
            cout << "Linked List is empty!" << endl;
            return NULL;
        }
        node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    node* deleteFromTail(node* head) {
        if (head == NULL) {
            cout << "Linked List is empty!" << endl;
            return NULL;
        }

        if (head->next == NULL) {
            delete head;
            return NULL;
        }
        
        node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }

        node* last = temp->next;
        temp->next = NULL;
        delete last;
        return head;
    }

    int get_last_node(node* head) {
        if (head == NULL) {
            cout << "No Node exists! LL empty" << endl;
            return -1;
        }
        node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        return temp->data;
    }
};


class stack{
    LinkedList l;
    node* head = NULL;
public:
    bool is_empty() {
        return l.is_empty(head);
    }

    void push(int x) {
        head = l.insertAtTail(x, head);
        return;
    }

    int pop() {
        if (l.is_empty(head)) {
            cout << "Stack is empty, cannot pop element" << endl;
            return -1;
        }
        int popped_element = l.get_last_node(head);
        head = l.deleteFromTail(head);
        return popped_element;
    }

    int peak() {
        if (l.is_empty(head)) {
            cout << "Stack is empty, cannot return peak element" << endl;
            return -1;
        }
        return l.get_last_node(head);
    }

};

int main() {
    stack s;
    for (int i = 1; i <= 10; i++) {
        s.push(i);
    }
    
    s.push(11);
    cout << s.pop() << endl;
    cout << s.peak() << endl;

    while (!s.is_empty()) {
        s.pop();
    }

    s.pop();
    cout << s.peak() << endl;
    return 0;
}