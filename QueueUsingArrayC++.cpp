#include<stdlib.h>
#include<iostream>
using namespace std;
class Queue{
	private:
		int size, front, rear, capacity;
		int ar[];
	public:
		Queue(int data)
		{
			size=0;
			front=0;
			capacity=data;
			rear=capacity-1;
		}
		bool isEmpty();
		bool isFull();
		int dequeue();
		void enqueue(int item);
		int Front();
		int Rear();		
};
bool Queue::isEmpty()
{
	return (size==0);
}
bool Queue::isFull()
{
	return (size==capacity);
}
void Queue:: enqueue(int item)
{
	if (isFull())
		return;
	rear=(rear+1)%capacity;
	ar[rear]=item;
	size++;
}
int Queue::dequeue()
{
	if(isEmpty())
		return INT_MIN;
	int item=ar[front];
	front=(front+1)%capacity;
	size--;
	return item;
}
int Queue::Front()
{
	if(isEmpty())
		return INT_MIN;
	return ar[front];
}
int Queue::Rear()
{
	if(isFull())
		return INT_MIN;
	return ar[rear];
}

int main()
{
	Queue q(100);
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	cout<<"Dequeued element is "<<q.dequeue()<<endl;
	cout<<"Front Element is "<<q.Front()<<endl;
	cout<<"Rear element is "<<q.Rear()<<endl;
	
}
