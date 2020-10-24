#include <iostream>
using namespace std;

class node{
public:
	int data;
	node* next;

	node(int d) {
		data = d;
		next = NULL;
	}
};

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

node* deleteAtHead(node* head) {
	if (head == NULL) {
		return NULL;
	}

	node* temp = head;
	head = head->next;
	delete temp;
	return head;
}

node* deleteAtTail(node* head) {
	if (head == NULL) {
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

	node* to_be_deleted = temp->next;
	temp->next = NULL;
	delete to_be_deleted;

	return head;
}

node* get_node(int d, node* head) {
	if (head == NULL) {
		return NULL;
	}

	node* temp = head;
	while (temp != NULL) {
		if (temp->data == d) {
			return temp;
		}
		temp = temp->next;
	}

	return NULL;
}

void print_list(node* head) {
	node* temp = head;
	while (temp != NULL) {
		cout << temp->data << " -> ";
		temp = temp->next;
	}
	cout << endl;
	return;
}

int main() {
	node* head = NULL;

	for (int i = 1; i <= 10; i++) {
		insertAtTail(i, head);
	}

	head = deleteAtHead(head);

	head = deleteAtTail(head);

	print_list(head);

	return 0;
}