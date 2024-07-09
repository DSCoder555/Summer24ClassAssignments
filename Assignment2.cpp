#include <iostream>
using namespace std;

// Node class: stores a node's value and a pointer to the next node
class Node {
	//your code goes here
    public:
        //Non-default constructor
        Node(int x){
            data = x;
            next = nullptr;
        }
        //next setter
        void setNext(Node* newNext){
            next = newNext;
        }
        //next getter
        Node* getNext(){
            return next;
        }
        //data getter
        int getValue(){
            return data;
        }
    private:
        int data;
        Node* next;
};
//LinkedList class: stores the head of a linked list and 
class LinkedList {
    public:
        LinkedList(){
            head = nullptr;
        }
        ~LinkedList();
        void addToFront(int num);
        void addToEnd(int num);
        bool remove(int num);
        void display() const;
    private:
        Node* head;
};
// Destructor: deletes Linked list object and destroys all of the points of the connected Nodes
LinkedList::~LinkedList() {
    Node* temp = head;
    while((*temp).getNext() != 0){
        Node* temp2 = temp->getNext();
        delete temp;
        temp = temp2;
    }
}
//AddToFront function: adds a new Node to the front of a LinkedList, making it the new head
void LinkedList::addToFront(int value) {
    Node* nodePoint = new Node(value);
    (*nodePoint).setNext(head);
    head = nodePoint;
}
//AddToEnd function: adds a new Node to the end of a LinkedList making the current end Node point to it
void LinkedList::addToEnd(int value) {
    Node* temp = head;
    while((*temp).getNext() != nullptr){
        temp = (*temp).getNext();
    }
    Node* nodePoint = new Node(value);
    (*temp).setNext(nodePoint);
}
//Remove function: if there is a Node with the given value in the list, it deletes that Node and returns true
// if there is no Node with the given value, returns false
bool LinkedList::remove(int value) {
    //your code goes here
    if((*head).getValue() == value){
        Node* temp = head;
        head = (*head).getNext();
        delete temp;
        return true;
    }
    Node* temp = head;
    while((*temp).getNext() != 0){
        Node* next = (*temp).getNext();
        if((*next).getValue()==value){
            temp->setNext(next->getNext());
            delete next;
            return true;
        }
    }
    return false;
}
// Prints out the values of all the nodes with a " -> " representing the connecting pointers
void LinkedList::display() const {
    Node* temp = head;
    while((temp) != nullptr){
        cout<<temp->getValue()<<" -> ";
        temp = temp->getNext();
    }
    cout<<"nullptr"<<endl;
}
// Main code testing the Node and Linked List Classes
int main() {
    LinkedList list;
    list.addToFront(3);
    list.addToEnd(5);
    list.addToFront(2);
    list.display(); // Output: 2 -> 3 -> 5 -> nullptr
    list.remove(3);
    list.display(); // Output: 2 -> 5 -> nullptr
    LinkedList list2;
    list2.addToFront(1); // List: 1 -> nullptr
    list2.addToEnd(2);   // List: 1 -> 2 -> nullptr
    list2.addToFront(0); // List: 0 -> 1 -> 2 -> nullptr
    list2.display();     // Output: 0 -> 1 -> 2 -> nullptr
    list2.remove(1);     // List: 0 -> 2 -> nullptr
    list2.remove(0);     // List: 2 -> nullptr
    list2.remove(3);     // No change, value 3 not found in the list
    list2.display();     // Output: 2 -> nullptr
    return 0;
}