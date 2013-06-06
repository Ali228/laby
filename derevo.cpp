#include <iostream>
#include <cctype>
#include <stdlib.h>
#include <conio.h>

using namespace std;

struct node
{
	int element;
	node *left;
	node *right;
	int height;
};
typedef struct node *nodeptr;
class bstree
{
	public:
		void insert(int,nodeptr &);
		void del(int, nodeptr &);
		int deletemin(nodeptr &);
		void find(int,nodeptr &);
		nodeptr findmin(nodeptr);
		nodeptr findmax(nodeptr);
		void makeempty(nodeptr &);
		void copy(nodeptr &,nodeptr &);
		nodeptr nodecopy(nodeptr &);
		void preorder(nodeptr);
		void inorder(nodeptr);
		void postorder(nodeptr);
		int bsheight(nodeptr);
		nodeptr srl(nodeptr &);
		nodeptr drl(nodeptr &);
		nodeptr srr(nodeptr &);
		nodeptr drr(nodeptr &);
		int max(int,int);
		int nonodes(nodeptr);
};
// Äîáàâëåíèå ýëåìåíòà
void bstree::insert(int x,nodeptr &p)
{
	if (p == NULL)
	{
		p = new node;
		p->element = x;
		p->left=NULL;
		p->right = NULL;
		p->height=0;
		if (p==NULL)
		{
			cout<<"Out of Space\n"<<endl;
		}
	}
	else
	{
		if (x<p->element)
		{
			insert(x,p->left);
			if ((bsheight(p->left) - bsheight(p->right))==2)
			{
				if (x < p->left->element)
				{
					p=srl(p);
				}
				else
				{
					p = drl(p);
				}
			}
		}
		else if (x>p->element)
		{
			insert(x,p->right);
			if ((bsheight(p->right) - bsheight(p->left))==2)
			{
				if (x > p->right->element)
				{
					p=srr(p);
				}
				else
				{
					p = drr(p);
				}
			}
		}
		else
		{
			cout<<"Element Exists\n"<<endl;
		}
}
int m,n,d;
m=bsheight(p->left);
n=bsheight(p->right);
d=max(m,n);
p->height = d + 1;
}
// Íàõîæäåíèå ìèíèìàëüíîãî ýëåìåíòà

nodeptr bstree::findmin(nodeptr p)
{
	if (p==NULL)
	{
		cout<<"Äåðåâî ïóñòîå\n"<<endl;
		return p;
	}
	else
	{
		while(p->left !=NULL)
		{
			p=p->left;
			//return p;
		}
		return p;
	}
}

// Íàõîæäåíèå ìàêñèìàëüíîãî ýëåìåíòà

nodeptr bstree::findmax(nodeptr p)
{
	if (p==NULL)
	{
		cout<<"Äåðåâî ïóñòîå\n"<<endl;
		return p;
	}
	else
	{
		while(p->right !=NULL)
		{
			p=p->right;
			//return p;
		}
		return p;
	}
}

// Íàõîæäåíèå ýëåìåíòà

void bstree::find(int x,nodeptr &p)
{
	if (p==NULL)
	{
		cout<<"Ýëåìåíò íå íàéäåí(((\n"<<endl;
	}
	else
	{
		if (x < p->element)
		{
			find(x,p->left);
		}
		else
		{
			if (x>p->element)
			{
				find(x,p->right);
			}
			else
			{
				cout<<"Ýëåìåíò íàéäåí!\n"<<endl;
			}
		}
	}
}

// Êîïèðîâàíèå äåðåâà
void bstree::copy(nodeptr &p,nodeptr &p1)
{
	makeempty(p1);
	p1 = nodecopy(p);
}
// Ïóñòîå äåðåâî
void bstree::makeempty(nodeptr &p)
{
	nodeptr d;
	if (p != NULL)
	{
		makeempty(p->left);
		makeempty(p->right);
		d=p;
		free(d);
		p=NULL;
	}
}
// Êîïèðîâàòü çíà÷åíèå
nodeptr bstree::nodecopy(nodeptr &p)
{
	nodeptr temp;
	if (p==NULL)
	{
		return p;
	}
	else
	{
		temp = new node;
		temp->element = p->element;
		temp->left = nodecopy(p->left);
		temp->right = nodecopy(p->right);
		return temp;
	}
}

// Óäàëåíèå çíà÷åíèÿ
void bstree::del(int x,nodeptr &p)
{
	nodeptr d;
	if (p==NULL)
	{
		cout<<"Óäàëÿåìûé æëåìåíò íå íàéäåí\n"<<endl;
	}
	else if ( x < p->element)
	{
		del(x,p->left);
	}
	else if (x > p->element)
	{
		del(x,p->right);
	}
	else if ((p->left == NULL) && (p->right == NULL))
	{
		d=p;
		free(d);
		p=NULL;
		cout<<"Ýëåìåíò óäàëåí óñïåøíî\n"<<endl;
	}
	else if (p->left == NULL)
	{
		d=p;
		free(d);
		p=p->right;
		cout<<"Ýëåìåíò óäàëåí óñïåøíî\n"<<endl;
	}
	else if (p->right == NULL)
	{
		d=p;
		p=p->left;
		free(d);
		cout<<"Ýëåìåíò óäàëåí óñïåøíî\n"<<endl;
	}
	else
	{
		p->element = deletemin(p->right);
	}
}
// óäàëåíèå ìèíèìàëüíîãî ýëåìåíòà
int bstree::deletemin(nodeptr &p)
{
	int c;
	cout<<"óäàëåíèå ìèíèìàëüíîãî ýëåìåíòà\n"<<endl;
	if (p->left == NULL)
	{
		c=p->element;
		p=p->right;
		return c;
	}
	else
	{
		c=deletemin(p->left);
		return c;
	}
}
// îáõîä â ïîðÿäêå 1

void bstree::preorder(nodeptr p)
{
	if (p!=NULL)
	{
		cout<<p->element<<"\t";
		preorder(p->left);
		preorder(p->right);
	}
}

// Îáõîä â ïîðÿäêå 2
void bstree::inorder(nodeptr p)
{
	if (p!=NULL)
	{
		inorder(p->left);
		cout<<p->element<<"\t";
		inorder(p->right);
	}
}

// Îáõîä â ïîðÿäêå 3
void bstree::postorder(nodeptr p)
{
	if (p!=NULL)
	{
		postorder(p->left);
		postorder(p->right);
		cout<<p->element<<"\t";
	}
}

 // ìàêñèìóì
int bstree::max(int value1, int value2)
{
	return ((value1 > value2) ? value1 : value2);
}
 // âûñîòà äåðåâà
int bstree::bsheight(nodeptr p)
{
	int t;
	if (p == NULL)
	{
		return -1;
	}
	else
	{
		t = p->height;
		return t;
	}
}

nodeptr bstree:: srl(nodeptr &p1)
{
	nodeptr p2;
	p2 = p1->left;
	p1->left = p2->right;
	p2->right = p1;
	p1->height = max(bsheight(p1->left),bsheight(p1->right)) + 1;
	p2->height = max(bsheight(p2->left),p1->height) + 1;
	return p2;
}
nodeptr bstree:: srr(nodeptr &p1)
{
	nodeptr p2;
	p2 = p1->right;
	p1->right = p2->left;
	p2->left = p1;
	p1->height = max(bsheight(p1->left),bsheight(p1->right)) + 1;
	p2->height = max(p1->height,bsheight(p2->right)) + 1;
	return p2;
}
nodeptr bstree:: drl(nodeptr &p1)
{
	p1->left=srr(p1->left);
	return srl(p1);
}
nodeptr bstree::drr(nodeptr &p1)
{
	p1->right = srl(p1->right);
	return srr(p1);
}

int bstree::nonodes(nodeptr p)
{
	int count=0;
	if (p!=NULL)
	{
		nonodes(p->left);
		nonodes(p->right);
		count++;
	}
	return count;
}

int main()
{
	setlocale(LC_ALL, "rus");
	//clrscr();
	nodeptr root,root1,min,max;//,flag;
	int a,choice,findele,delele;
	char ch='y';
	bstree bst;

	//system("clear");
	root = NULL;
	root1=NULL;
	cout<<"\n\t\t\t\tÎâñÿííèêîâ èó8-21 ëàáîðàòîðíàÿ ðàáîòà ¹5"<<endl;
	cout<<"\t\t\t\t:::::::::::::::::::::::::::::::::::::::::::::\n"<<endl;

	do
	{
		cout<<"\t\t:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
		cout<<"\t\t::::Ââåäèòå 1 äëÿ äîáàâëåíèÿ ýëåìåíòà::::::::::::::::::::::::"<<endl;
		cout<<"\t\t::::Ââåäèòå 2 äëÿ íàõîæäåíèÿ ìèíèìàëüíîãî çíà÷åíèÿ:::::::::::"<<endl;
		cout<<"\t\t::::Ââåäèòå 3 äëÿ íàõîæäåíèÿ ìàêñèìàëüíîãî çíà÷åíèÿ::::::::::"<<endl;
		cout<<"\t\t::::Ââåäèòå 4 äëÿ ïîèñêà ýëåìåíòà::::::::::::::::::::::::::::"<<endl;
		cout<<"\t\t::::Ââåäèòå 5 äëÿ óäàëåíèÿ çíà÷åíèÿ::::::::::::::::::::::::::"<<endl;
		cout<<"\t\t::::Ââåäèòå 6 îáõîä â ïîðÿäêå 1::::::::::::::::::::::::::::::"<<endl;
		cout<<"\t\t::::Ââåäèòå 7 îáõîä â ïîðÿäêå 2::::::::::::::::::::::::::::::"<<endl;
		cout<<"\t\t::::Ââåäèòå 8 îáõîä â ïîðÿäêå 3::::::::::::::::::::::::::::::"<<endl;
		cout<<"\t\t::::Ââåäèòå 9 äëÿ íàõîæäåíèÿ âûñîòû äåðåâà:::::::::::::::::::"<<endl;
		cout<<"\t\t::::Ââåäèòå 0 äëÿ âûõîäà èç ïðîãðàììû::::::::::::::::::::::::"<<endl;
		cout<<"\t\t:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n"<<endl;

		cout<<"\nÂâåäèòå ñâîé âûáîð: ";
		cin>>choice;

		switch(choice)
		{
			case 1:
				cout<<"\n\t\tÄîáàâüòå ýëåìåíò"<<endl;
				cout<<"\t\t:::::::::::::\n"<<endl;
				cout<<"Ââåäèòå çíà÷åíèå: ";
				cin>>a;
				bst.insert(a,root);
				cout<<"\nÍîâîå çíà÷åíèå äîáàâëåíî óñïåøíî)))\n"<<endl;
				break;
			case 2:
				if (root !=NULL)
		   	    {
					min=bst.findmin(root);
					cout<<"\nÌèíèìàëüíûé ýëåìåíò â äåðåâå: "<<min->element<<endl;
				}
				break;
	    	case 3:
				if (root !=NULL)
				{
					max=bst.findmax(root);
					cout<<"\nÌàêñèìàëüíûé ýëåìåíò â äåðåâå: "<<max->element<<endl;
				}
				break;
			case 4:
				cout<<"\nÂâåäèòå ýëåìåíò äëÿ ïîèñêà: ";
				cin>>findele;
				if (root != NULL)
				{
					bst.find(findele,root);
				}
				break;
			case 5:
				cout<<"\nÂâåäèòå ýëåìåíò äëÿ óäàëåíèÿ: ";
				cin>>delele;
				bst.del(delele,root);
				bst.inorder(root);
				cout<<endl;
				break;
			case 6:
				cout<<"\n\t\tÎáõîä â ïîðÿäêå 1"<<endl;
				bst.preorder(root);
				cout<<endl;
				break;
			case 7:
				cout<<"\n\t\tÎáõîä â ïîðÿäêå 2"<<endl;
				bst.inorder(root);
				cout<<endl;
				break;
			case 8:
				cout<<"\n\t\tÎáõîä â ïîðÿäêå 3"<<endl;
				bst.postorder(root);
				cout<<endl;
				break;
			case 9:
				cout<<"\n\t\tÂûñîòà\n"<<endl;
				cout<<"Âûñîòà äåðåâà: "<<bst.bsheight(root)<<endl;

				break;
			case 0:
				cout<<"\n\tÂîò òàê ðàáîòàåò ïðîãðàììà,ñïàñèáî)))\n"<<endl;
				break;
			default:
				cout<<"Âû ââåëè íåâåðíûé ïóíêò ìåíþ\n"<<endl;
				break;
		}
		system("pause");
		system("cls");
	}while(choice != 0);
	return 0;
}