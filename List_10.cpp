#include <iostream>
#include <unordered_set>

using namespace std;

template <typename T>
struct Node {
    T data;
    Node* prev;
    Node* next;
    Node(T val) : data(val), prev(nullptr), next(nullptr) {}
};

template <typename T>
void removeDuplicates(Node<T>* head) {
    if (!head) return;

    unordered_set<T> seen;
    Node<T>* current = head;

    while (current) {
        if (seen.find(current->data) != seen.end()) {
            Node<T>* toDelete = current;

            if (current->prev) {
                current->prev->next = current->next;
            }
            if (current->next) {
                current->next->prev = current->prev;
            }

            current = current->next;

            delete toDelete;
        }
        else {
            seen.insert(current->data);
            current = current->next;
        }
    }
}

template <typename T>
void printList(Node<T>* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    Node<int>* head = new Node<int>(3);
    Node<int>* n1 = new Node<int>(1);
    Node<int>* n2 = new Node<int>(2);
    Node<int>* n3 = new Node<int>(3);
    Node<int>* n4 = new Node<int>(4);
    Node<int>* n5 = new Node<int>(2);
    Node<int>* n6 = new Node<int>(5);

    head->next = n1;
    n1->prev = head; n1->next = n2;
    n2->prev = n1; n2->next = n3;
    n3->prev = n2; n3->next = n4;
    n4->prev = n3; n4->next = n5;
    n5->prev = n4; n5->next = n6;
    n6->prev = n5;

    cout << "Исходный список: ";
    printList(head);

    removeDuplicates(head);

    cout << "Список без дубликатов: ";
    printList(head);

    return 0;
}