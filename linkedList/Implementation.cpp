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
int lenghtOfLL(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp)
    {

        temp = temp->next;
        count++;
    }
    return count;
}
int checkIfPresent(Node *head, int data1)
{
    Node *temp = head;
    while (temp)
    {
        if (temp->data == data1)
            return 1;
        temp = temp->next;
    }
    return 0;
}
void print(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
Node *deleteHead(Node *head)
{
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}
Node *deleteTail(Node *head)
{
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next->next;
    temp->next = nullptr;
    return head;
}
Node *deleteIndex(Node *head, int k)
{
   if(head==NULL)return head;
   if(k==1){
    Node *temp=head;
    head=head->next;
    free(temp);
    return head;
   }
   int cnt=0;
   Node *temp=head;
   Node *prev=NULL;
   while(temp!=NULL){
    cnt++;
    if(cnt==k){
        prev->next=prev->next->next;
        free(temp);
        break;
    }
    prev=temp;
    temp=temp->next;
   }
   return head;
}
Node *insertEleAtHead(Node *head,int k){
    Node *temp;
    temp->data=k;
    temp->next=head;
    return temp;
}
Node *insertEleAtTail(Node *head,int k){
    if(head==NULL)return new Node(k,NULL);
    Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    } 
    Node *temp2;
    temp->next=temp2; 
    temp2->data=k;
    temp2->next=NULL;
    return head;

}
Node *insertAtIndex(Node *head,int index,int ele){
    if(index==1){
        Node *temp=new Node(ele,head);
    
    return temp;
    }
    Node *temp=head;
    int cnt=1;
    while(temp!=NULL){
        cnt++;
        if(cnt==index){
            Node *temp2=new Node(ele,temp->next);
            temp->next=temp2;
        }
        temp=temp->next;
    }
    return head;
}

int main()
{
    int arr[5] = {12, 2, 3, 4, 5};
    Node *head = arrToLinkedList(arr);
    head=insertAtIndex(head,6,23);
    print(head);
    return 0;
}