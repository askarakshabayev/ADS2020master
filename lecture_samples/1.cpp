#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node *next, *prev;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LinkedList {
    public:
    Node *front, *tail;

    LinkedList() {
        front = NULL;
        tail = NULL;
    }

    void push_back(int data) {
        Node *node = new Node(data);

        if (tail == NULL) {
            tail = node;
            front = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    void push_front(int data) {
        Node *node = new Node(data);

        if (front == NULL) {
            front = node;
            tail = node;
        } else {
            front->prev = node;
            node->next = front;
            front = node;
        }
    }

    void print() {
        Node *node = front;
        while (node != NULL) {
            cout << node->data << " ";
            node = node->next;
        }
    }

    void pop_back() {
        if (tail != NULL) {
            tail = tail->prev;
            if (tail != NULL) {
                tail->next = NULL;
            } else {
                front = NULL;
            }
        }
    }

    void pop_front() {
        if (front != NULL) {
            front = front->next;
            if (front != NULL)
                front->prev = NULL;
            else
                tail = NULL;
        }
    }

    void insert(Node *a, int data) {
        if (a == tail) {
            push_back(data);
            return;
        }
        Node *b = a->next;

        Node *node = new Node(data);
        a->next = node;
        node->prev = a;
        b->prev = node;
        node->next = b;
    }

    Node* find_el(int data) {
        Node *node = front;
        while (node != NULL) {
            if (node->data == data)
                return node;
            node = node->next;
        }
        return NULL;
    }

    void delete_el(Node *node) {
        if (node == tail)
            pop_back();
        else if (node == front)
            pop_front();
        else {
            Node *a = node->prev;
            Node *b = node->next;
            a->next = b;
            b->prev = a;
        }
    }
};

class Stack {
    public:
    Node *tail;
    int sz;

    Stack() {
        tail = NULL;
        sz = 0;
    }
    
    void pop() {
        if (tail != NULL) {
            tail = tail->prev;
            sz--;        
            if (tail != NULL)
                tail->next = NULL;
        }
    }

    void push(int data) {
        sz++;
        Node *node = new Node(data);

        if (tail == NULL)
            tail = node;
        else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    Node* top() {
        return tail;
    }

    bool empty() {
        if (tail == NULL)
            return true;
        return false;
    }
   
    int size() {
        return sz;
    }
};

int main() {
    LinkedList *ll = new LinkedList();
    ll->push_back(20);
    ll->push_back(10);
    ll->push_front(40);
    ll->push_front(5);
    ll->pop_back();
    ll->pop_front();
    ll->insert(ll->front, 30);
    ll->insert(ll->front, 35);
    Node *node = ll->find_el(30);
    ll->insert(node, 25);
    ll->delete_el(node);
    ll->print();
    return 0;
}