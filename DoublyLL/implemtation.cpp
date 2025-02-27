#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*prev;
    Node*next;

    Node(int val){
        data=val;
        prev=nullptr;
        next=nullptr;
    }
   

};
// Node* insertAtStart(Node*head,int val){
//     if(head==nullptr){
//         head=new Node(val);
//         return head;
//     }
//     else{
//         Node*temp=new Node(val);
//         temp->next=head;
//         return temp;
//     }
// }
class LinkedList{
    public:
    Node *head;

    LinkedList(){
        head=nullptr;
    }
    void insertAtStart(int val) {
        Node* temp = new Node(val);
        if (head != nullptr) {
            temp->next = head;
            head->prev = temp;
        }
        head = temp;
    }
    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main(){
    LinkedList ll;
    int arr[5]={1,2,3,4,5};
    ll.insertAtStart(5);
    ll.insertAtStart(7);
    ll.insertAtStart(3);


    ll.printList();
    return 0;
}