// Online C++ compiler to run C++ program online
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define SIZE 4

class QueueArray{
  int front,rear;
  int *queue;
  public:
    QueueArray(){
      queue=new int[SIZE];
      front = -1;
      rear = -1;
    }
      void enQueue(int data);
      int deQueue();
};
// Add data to the circular queue
void QueueArray::enQueue(int data) {
    if ((rear + 1) % SIZE == front) { 
        return;  // Queue overflow, do nothing
    }
    
    if (front == -1) { // First insertion
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }

    queue[rear] = data;
}

// Remove first element from queue
int QueueArray::deQueue() {
    if (front == -1) {
        return -1; // Queue underflow
    }

    int data = queue[front];

    if (front == rear) { // Last element being removed
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }

    return data;
}


int main(){
  
    QueueArray q1;
    q1.enQueue(5);
    q1.enQueue(3);
    cout<<q1.deQueue();
    q1.enQueue(4);
    cout<<q1.deQueue();
    cout<<q1.deQueue();

   
  return 0;
}