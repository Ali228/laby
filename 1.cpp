#include <iostream>
#include <conio.h>
using namespace std;

struct List
{
	int value;
	List *next;
	void add(int v, int n, List *p, List *first)
	{
		for(int i=0; i<n; i++)
		{
			p=first;
			first=first->next;
		}
		p->value = v;
	}
	void get_val(int n, List *p, List *first)
	{
		for(int i=0; i<n ; i++)
		{
			p=first;
			first= first->next;
		}
		cout << "Element: " << p->value;
	}
	void del(int n, List *p, List *first)
	{
		for(int i=0; i<n; i++)
		{
			p=first;
			first= first->next;
		}
		delete p;
	}
};

int main()
{
	List *first = 0;
	List *p;
	int size, n;
	cout << "Input size: ";
	cin >> size;
	p = new List;
	for (int i=0; i<size; i++)
	{
		p = new List;
		p->value=0;
		p->next=first;
		first=p;
	}
	for(int i=0; i<size; i++)
		p->add(rand()%100+1,i,p,first);
	cout << "Input number: ";
	cin >> n;
	p->get_val(n,p,first);
	cout << "\nInput element to delete it: ";
	cin >> n;
	p->del(n,p,first);
	getch();

}