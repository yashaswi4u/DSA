#include<iostream>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next)return head;
        ListNode*temp=head;
        ListNode*leftptr=head;
        ListNode*rightptr=head;
        while(leftptr->next->val!=left){
            leftptr=leftptr->next;
        }
         while(rightptr->val!=right){
            rightptr=rightptr->next;
        }
       ListNode*prev=NULL;
       ListNode*current=leftptr->next;
       ListNode*next;
       
       int count=0;
     
       while(current && current!=rightptr->next){
        next=current->next;
        cout<<current->val;
        current->next=prev;
        prev=current;
        current=next;
        count++;
       }
     
       leftptr->next=prev;
    //    cout<<prev->val;
    //      while(temp!=NULL){
    //     cout<<temp->val;
    //     temp=temp->next;
    //    }
    //    if(prev){
    //      while(prev->next!=NULL){
    //     prev=prev->next;
    //    }
    //    }
    //   if(prev){
    //     prev->next=rightptr->next;
    //   }
       
       return head;
    }
};

ListNode* createLinkedList(int arr[], int size) {
    if(size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for(int i = 1; i < size; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Function to print a linked list
void printLinkedList(ListNode* head) {
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int left = 2, right = 4;
    
    ListNode* head = createLinkedList(arr, 6);
    cout << "Original list: ";
    printLinkedList(head);

    Solution solution;
    head = solution.reverseBetween(head, left, right);

    cout << "\nModified list: ";
    printLinkedList(head);

    return 0;
}