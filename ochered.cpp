#include <iostream>
#include <conio.h>
using namespace std;

void add(int *queue, int n)
{
	queue[n]=rand()%100+1;
}

void del(int *queue, int n, int size)
{
	int *temp;
	temp = new int[size-1];
	for (int i=0; i<n; i++)
		temp[i]=queue[i];
	for(int i=n; i<size-1; i++)
		temp[i]=queue[i+1];
	delete queue;
	queue = new int [size-1];
	for (int i=0; i<size-1; i++)
		queue[i]=temp[i];
	delete temp;
}

void get_val(int *queue, int n)
{
	cout << "Value: " << queue[n];
}

int main()
{
	int *queue, size, n;
	cout << "Input size of queue: ";
	cin >> size;
	queue = new int[size];
	for(int i=0; i<size; i++)
		add(queue,i);
	cout << "Input number: ";
	cin >> n;
	get_val(queue,n);
	cout << "\nInput number to delete it: ";
	cin >> n;
	del(queue,n,size);
	getch();
}