#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data1, Node *ptr1)
    {
        data = data1;
        next = ptr1;
    }
};
Node *arrToLinkedList(int arr[])
{
    Node *mover = new Node(arr[0], nullptr);
    Node *head = mover;
    for (int i = 1; i < 5; i++)
    {
        Node *temp = new Node(arr[i], nullptr);
        mover->next = temp;
        mover = mover->next; // mover=temp
    }
    return head;
}
int lenghtOfLL(Node *head){
    Node *temp = head;
    int count=0;
    while (temp)
    {
        
        temp = temp->next;
        count++;
    }
    return count;
}
int checkIfPresent(Node *head,int data1){
    Node *temp = head;
    while (temp)
    {
        if(temp->data==data1)return 1;
        temp = temp->next;
    }
    return 0;
}
int main()
{
    int arr[5] = {12, 2, 3, 4, 5};
    Node *head = arrToLinkedList(arr);
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    int check=checkIfPresent(head,6);
    cout<<check;
    return 0;
}