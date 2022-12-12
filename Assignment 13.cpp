#include<iostream>
#include<string>
using namespace std;

class Queue
{
	int deque[10];
	int front;
	int rear;
	public:	Queue(){
		front = -1;
		rear = -1;
	}
	public:void enqueue_front(int x){
		if((front == rear+1) || ((front ==0) && (rear == 9))){
			cout<<"Queue is Full "<<endl;
		}
		else if(front==-1 && rear ==-1){
			front=rear=0;
			deque[front]=x;
		}
		else if(front ==0){
			front = 9;
			deque[front]=x;
		}
		else{
			front--;
			deque[front]=x;
		}
	}
	public:void enqueue_rear(int x){
		if((front == rear+1) || ((front ==0) && (rear == 9))){
			cout<<"Queue is Full "<<endl;
		}
		else if(front==-1 && rear ==-1){
			front=rear=0;
			deque[rear]=x;
		}
		else if(rear==9){
			rear=0;
			deque[rear]=x;
		}
		else{
			rear++;
			deque[rear]=x;
		}
	}
	public:void display(){
		int i =front;
		while(i!=rear){
			cout<<deque[i]<<" "<<endl;
			i = (i+1)%10;
		}
		cout<<deque[rear]<<endl;
	}
	public: void dequeue_front(){
		if(front==-1 && rear ==-1){
			cout<<"Empty";
		}
		else if(front==rear){
			front=rear=-1;
		}
		else if(front == 9){
			cout<<"Deque value is :"<<" "<<deque[front];
			front = 0;
		}
		else{
			cout<<"Deque value is :"<<" "<<deque[front];
			front++;
		}
	}
	public: void dequeue_rear(){
		if(front==-1 && rear ==-1){
			cout<<"Empty";
		}
		else if(front==rear){
			front=rear=-1;
		}
		else if(rear==0){
			cout<<"Deque value is :"<<" "<<deque[rear];
			rear = 9;
		}
		else{
			cout<<"Deque value is :"<<" "<<deque[rear];
			rear--;
		}
	}
};
int main(){
	Queue q1;
	q1.enqueue_front(1);
	q1.enqueue_rear(10);
	q1.enqueue_front(2);
	q1.enqueue_rear(9);
	q1.enqueue_front(3);
	q1.enqueue_front(4);
	q1.display();
	q1.dequeue_rear();
	q1.dequeue_front();
	q1.dequeue_rear();
	q1.dequeue_front();
	q1.display();
	return 0;
}