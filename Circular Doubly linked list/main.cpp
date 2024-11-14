#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;

    Node(int d) {
        data = d;
        next = prev = nullptr;
    }
};

struct CDLL {
    Node *head = nullptr;

    void InsertAtHead(int d);
    void InsertAtEnd(int d);
    void InsertAtAnyPosition(int d, int position);
    void DeleteHead();
    void DeleteTail();
    void DeleteAnyPosition(int position);
    int MaximumValue();
    int MinimumValue();
    void SearchItem(int value);
    void Print();
};

void CDLL::Print() {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    Node *temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

void CDLL::InsertAtHead(int d) {
    Node *n = new Node(d);
    if (head == nullptr) {
        head = n;
        n->next = n->prev = head;
    } else {
        Node *last = head->prev;
        n->next = head;
        n->prev = last;
        last->next = head->prev = n;
        head = n;
    }
}

void CDLL::InsertAtEnd(int d) {
    Node *n = new Node(d);
    if (head == nullptr) {
        head = n;
        n->next = n->prev = head;
    } else {
        Node *last = head->prev;
        n->next = head;
        n->prev = last;
        last->next = head->prev = n;
    }
}

void CDLL::InsertAtAnyPosition(int d, int position) {
    Node *n = new Node(d);
    if (position == 1) {
        InsertAtHead(d);
    } else {
        Node *temp = head;
        for (int i = 1; i < position - 1 && temp->next != head; i++) {
            temp = temp->next;
        }
        n->next = temp->next;
        n->prev = temp;
        temp->next->prev = n;
        temp->next = n;
    }
}

void CDLL::DeleteHead() {
    if (head == nullptr) return;
    if (head->next == head) {
        delete head;
        head = nullptr;
    } else {
        Node *last = head->prev;
        Node *temp = head;
        head = head->next;
        head->prev = last;
        last->next = head;
        delete temp;
    }
}

void CDLL::DeleteTail() {
    if (head == nullptr) return;
    if (head->next == head) {
        delete head;
        head = nullptr;
    } else {
        Node *last = head->prev;
        last->prev->next = head;
        head->prev = last->prev;
        delete last;
    }
}

void CDLL::DeleteAnyPosition(int position) {
    if (head == nullptr) return;
    if (position == 1) {
        DeleteHead();
    } else {
        Node *temp = head;
        for (int i = 1; i < position && temp->next != head; i++) {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }
}

int CDLL::MaximumValue() {
    if (head == nullptr) return -1;
    Node *temp = head;
    int maxVal = head->data;
    do {
        if (temp->data > maxVal) maxVal = temp->data;
        temp = temp->next;
    } while (temp != head);
    cout << "Max Value: " << maxVal << endl;
    return maxVal;
}

int CDLL::MinimumValue() {
    if (head == nullptr) return -1;
    Node *temp = head;
    int minVal = head->data;
    do {
        if (temp->data < minVal) minVal = temp->data;
        temp = temp->next;
    } while (temp != head);
    cout << "Min Value: " << minVal << endl;
    return minVal;
}

void CDLL::SearchItem(int value) {
    Node *temp = head;
    int position = 1;
    do {
        if (temp->data == value) {
            cout << "Value " << value << " found at position " << position << endl;
            return;
        }
        temp = temp->next;
        position++;
    } while (temp != head);
    cout << "Value " << value << " not found" << endl;
}


int main() {
    CDLL lists;
    lists.InsertAtHead(10);
    lists.InsertAtHead(20);
    lists.InsertAtEnd(30);
    lists.InsertAtAnyPosition(25, 2);
    lists.Print();
    lists.DeleteAnyPosition(3);
    lists.Print();
    lists.MaximumValue();
    lists.MinimumValue();
    lists.SearchItem(30);
    lists.DeleteHead();
    lists.Print();
    lists.DeleteTail();
    lists.Print();
}

