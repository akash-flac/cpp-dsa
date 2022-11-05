#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node *next;

    //constructor
    Node(int data){
        this -> data = data;
        this -> next =  NULL;
    }
};

void insertAtHead(Node* &head, int d){
    Node* temp = new Node(d);
    temp -> next = head ;
    head = temp ;
}

void print(Node* &head) {
    Node* temp = head ;

    while( temp != NULL){
        cout << temp -> data << " " ;
        cout << temp -> next << endl ;
        temp = temp -> next ; 
    }

}

int main(){
    // creating a new node
    Node* node1 = new Node(12);
    cout << node1 -> data << endl ; 
    cout << node1 -> next << endl ;

    //pointing head to node1
    Node* head = node1;
    insertAtHead(head, 15);
    insertAtHead(head, 17);
    insertAtHead(head, 89);

    print(head); 




}