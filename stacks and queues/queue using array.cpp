#include <bits/stdc++.h> 
class Queue {
public:
   int *array;
   int size;
   int qfront;
   int rear;
   Queue() 
   {
       size = 10001;
       array = new int[size];
       qfront = 0;
       rear = 0;
   }
   bool isEmpty() 
   {
       if(rear == 0)
       {
           return true;
       }
       if(rear == qfront)
       {
           return true;
       }
       else
       {
           return false;
       }
   }
   void enqueue(int data) 
   {
       array[rear] = data;
       rear++;
   }
   int dequeue() 
   {
       if(qfront == rear)
       {
           qfront = 0;
           rear = 0;
           return -1;
       }
       int ans = array[qfront];
       qfront++;
       return ans;
   }
   int front() 
   {
       if(rear == 0)
       {
           return -1;
       }
       if(rear == qfront)
       {
           return -1;
       }
       return array[qfront];
   }
};
