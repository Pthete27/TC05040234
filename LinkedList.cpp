#include <iostream>
using namespace std;
class Node 
{
public:
    int data;
    Node* next;
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};
class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = nullptr;
    }
    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout <<endl;
    }
};

int main() {
    LinkedList list;
    list.insert(5);
    list.insert(10);
    list.insert(15);
    list.insert(20);
    cout << "Linked List: ";
    list.display();

    return 0;
}
