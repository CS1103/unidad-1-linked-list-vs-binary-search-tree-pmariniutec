//
// Created by ruben on 4/5/19.
//

#include "LinkedList.h"

UTEC::LinkedList::LinkedList() {

}

UTEC::LinkedList::~LinkedList() {

}

int UTEC::LinkedList::size() {
    int count = 0;
    Node* actual = head;
    while(actual != nullptr) {
        count++;
        actual = actual->next;
    }
    return count;
}

bool UTEC::LinkedList::is_empty() {
    return head == nullptr;
}

UTEC::Node *UTEC::LinkedList::get_head() {
    return head;
}

UTEC::Node *UTEC::LinkedList::get_tail() {
    return tail;
}

void UTEC::LinkedList::add_head(const Location& data) {
    Node* temp = new Node(data);
    if (is_empty()) {
        tail = temp;
        head = temp;
    } else {
        temp->next = head;
        head = temp;
    }
}

void UTEC::LinkedList::add_tail(const Location& data) {
    Node* temp = new Node(data);
    if (is_empty()) {
        tail = temp;
        head = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}
