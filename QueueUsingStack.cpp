//this method makes the dequeue function costly
#include<iostream>
#include<stack>
#include<stdlib.h>
using namespace std;

class Queue{
	stack<int> q;
	stack<int> rev;
	private:
	int front;
	public:
		Queue(){
		}
		int dequeue();
		void enqueue(int item);
		int rear();
		int Front();
		int size();
	
};
int Queue::size()
{
	return q.size();
}
int Queue::dequeue()
{
	
	while(!q.empty())
	{
		rev.push(q.top());
		q.pop();
	}
	int item=rev.top();
	rev.pop();
	front=rev.top();
	while(!rev.empty())
	{
		q.push(rev.top());
		rev.pop();	
	}
	return item;
}
int Queue::rear()
{
	return q.top();
}

void Queue::enqueue(int item)
{
	q.push(item);	
}
int Queue::Front()
{
	return front;
}
int main()
{
	Queue q;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	cout<<"Size of queue is "<<q.size()<<endl;
	cout<<"Element dequeued is "<<q.dequeue()<<endl;
	cout<<"Size of queue is "<<q.size()<<endl;
	cout<<"Front element is "<<q.Front()<<endl;
	cout<<"Rear element is "<<q.rear()<<endl;
	
}
