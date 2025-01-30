#include <bits/stdc++.h>
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

Node* insertBegM2(Node* head, int k) {
    Node* temp = new Node(k);
    if (head == nullptr) {
        temp->next = temp;
        return temp;
    } else {
        temp->next = head->next;
        head->next = temp;
        swap(head->key, temp->key);
        return head;
    }
}

Node* insertEndM2(Node* head, int k) {
    Node* temp = new Node(k);
    if (head == nullptr) {
        temp->next = temp;
        return temp;
    } else {
        temp->next = head->next;
        head->next = temp;
        swap(head->key, temp->key);
        return temp;
    }
}

Node* insertPos(Node* head, int k, int pos) {
    Node* temp = new Node(k);
    if (head == nullptr || pos == 1) {
        temp->next = temp;
        return temp;
    }

    Node* curr = head;
    for (int i = 0; i < pos - 2; ++i) {
        if (curr->next == head) {
            break;
        }
        curr = curr->next;
    }

    temp->next = curr->next;
    curr->next = temp;
    return head;
}

Node* deleteHead(Node* head) {
    if (head == nullptr) {
        return nullptr;
    } else if (head->next == head) {
        delete head;
        return nullptr;
    } else {
        head->key = head->next->key;
        Node* temp = head->next;
        head->next = head->next->next;
        delete temp;
        return head;
    }
}

Node* deletePos(Node* head, int pos) {
    if (head == nullptr) {
        return nullptr;
    } else if (pos == 1) {
        return deleteHead(head);
    }

    Node* curr = head;
    for (int i = 0; i < pos - 2; ++i) {
        curr = curr->next;
    }

    Node* temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
    return head;
}

int lengthOfList(Node* head) {
    int c = 1;
    if (head == nullptr) {
        return 0;
    }
    Node* curr = head->next;
    while (curr != head) {
        curr = curr->next;
        ++c;
    }
    return c;
}

Node* deleteLast(Node* head) {
    int pos = lengthOfList(head);
    return deletePos(head, pos);
}

void printCC(Node* head) {
    if (head == nullptr) {
        return;
    }
    cout << head->key << " ";
    Node* curr = head->next;
    while (curr != head) {
        cout << curr->key << " ";
        curr = curr->next;
    }
}

int main() {
    // Inserting Data
    Node* head = new Node(5);
    head->next = new Node(10);
    head->next->next = new Node(15);
    head->next->next->next = new Node(30);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = head;

    head = insertBegM2(head, 4);
    head = insertBegM2(head, 2);
    head = insertEndM2(head, 99);
    head = insertPos(head, 3, 2);
    head = insertPos(head, 7, 5);

    printCC(head);
    cout << "\n";

    // Deleting Data
    head = deleteHead(head);
    head = deletePos(head, 2);
    head = deleteLast(head);

    printCC(head);
    return 0;
}