//this method makes the dequeue function costly
#include<iostream>
#include<stack>
#include<stdlib.h>
using namespace std;

class Queue{
	stack<int> q;	
	private:
	int front;
	int deleted;
	public:
		Queue(){
		}
		int dequeue();
		void enqueue(int item);
		void Deleting();
		int rear();
		int Front();
		int size();
		
	
};
int Queue::size()
{
	return q.size();
}
void Queue::Deleting()
{	
	if(q.size()==1)
	{
		deleted=q.top();
		q.pop();
		return;
	}
	if(q.size()==2)
	front=q.top();
	
	int tem= q.top();
	q.pop();
	Deleting();
	q.push(tem);	
}
int Queue::dequeue()
{
	if (q.size()==0)
	return INT_MIN;
	Deleting();
	return deleted;
}
int Queue::rear()
{
	if(q.size()==0)
	return INT_MIN;
	return q.top();
}

void Queue::enqueue(int item)
{
	q.push(item);
	if(q.size()==1)
	front=q.top();	
}
int Queue::Front()
{
	if(q.size()==0)
	return INT_MIN;
	return front;
}
int main()
{
	Queue q;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(60);
	cout<<"Size of queue is "<<q.size()<<endl;
	while(!(q.size()==0))
	{
		cout<<"Element dequeued is "<<q.dequeue()<<endl;
	cout<<"Size of queue is "<<q.size()<<endl;
	cout<<"Front element is "<<q.Front()<<endl;
	cout<<"Rear element is "<<q.rear()<<endl;
	}
	
	
}
