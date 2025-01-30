#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int key;
    Node* next;

    Node(int k) {
        key = k;
        next = nullptr;
    }
};

void printHead(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->key << " ";
        curr = curr->next;
    }
    cout << "\n";
}

Node* insertBegin(Node* head, int k) {
    Node* temp = new Node(k);
    temp->next = head;
    return temp;
}

Node* insertEnd(Node* head, int k) {
    if (head == nullptr) {
        return new Node(k);
    }
    Node* curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = new Node(k);
    return head;
}

Node* insertPos(Node* head, int data, int pos) {
    Node* temp = new Node(data);
    if (pos == 1) {
        temp->next = head;
        return temp;
    }
    Node* curr = head;
    for (int i = 0; i < pos - 2; i++) {
        if (curr == nullptr) {
            return head; // Position out of bounds
        }
        curr = curr->next;
    }
    temp->next = curr->next;
    curr->next = temp;
    return head;
}

Node* deleteBegin(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }
    Node* newHead = head->next;
    delete head;
    return newHead;
}

Node* deleteLast(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        delete head;
        return nullptr;
    }
    Node* curr = head;
    while (curr->next->next != nullptr) {
        curr = curr->next;
    }
    delete curr->next;
    curr->next = nullptr;
    return head;
}

Node* deletePos(Node* head, int pos) {
    if (pos == 1) {
        Node* newHead = head->next;
        delete head;
        return newHead;
    }
    Node* curr = head;
    for (int i = 0; i < pos - 2; i++) {
        if (curr->next == nullptr) {
            return head; // Position out of bounds
        }
        curr = curr->next;
    }
    Node* temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
    return head;
}

void searchItem(Node* head, int item) {
    Node* curr = head;
    int position = 1;
    while (curr != nullptr) {
        if (curr->key == item) {
            cout << item << " Key is found at node " << position << "\n";
            return;
        }
        position++;
        curr = curr->next;
    }
    cout << item << " Key not found.\n";
}

int main() {
    Node* head = nullptr;
    Node* temp1 = new Node(10);
    Node* temp2 = new Node(20);
    Node* temp3 = new Node(30);
    Node* temp4 = new Node(40);
    
    temp1->next = temp2;
    temp2->next = temp3;
    temp3->next = temp4;
    head = temp1;

    head = insertBegin(head, 5);
    head = insertBegin(head, 15);
    head = insertEnd(head, 100);
    head = insertPos(head, 25, 2);

    printHead(head);

    head = deletePos(head, 3);
    printHead(head);

    return 0;
}