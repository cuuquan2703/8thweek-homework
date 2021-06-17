#include<iostream>
using namespace std;

struct node
{
	int key;
	node* next;
};

void init(node*& head)
{
	head = NULL;
}


node* getnode(int data)
{
	node* k;
	k = new node;
	k->key = data;
	k->next = NULL;
	return k;
}
void addFirst(node*& head, int k)
{
	node* p = getnode(k);
	if (head == NULL)
		head = p;
	else {
		p->next = head;
		head = p;
	}
}
void addTail(node*& head, int k)
{
	node* temp = head;
	node* q = getnode(k);
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = q;
}
void deletenode(node*& head, int n)
{
	node* p, * k;
	while (head && head->key == n)
	{
		p = head;
		head = head->next;
		//deleteNode(p);
	}

	if (head != NULL)
	{
		p = head;
		k = head->next;
		while (k != NULL)
		{
			if (k->key != n)
			{
				p->next = k;
				p = k;
			}
			k = k->next;
		}

		p->next = NULL;
		//l.pTail = p;
	}
}
void delete_replica(node*& head, int n)
{
	node* p, * k;
	int count = 0;
	while (head && head->key == n)
	{
		p = head;
		head = head->next;
		//deleteNode(p);
	}

	if (head != NULL)
	{
		p = head;
		k = head->next;
		while (k != NULL)
		{
			if (k->key == n) count++;
			if (k->key != n || count == 1)
			{
				p->next = k;
				p = k;
			}
			//else if (k->key == n) count++;
			//if (k->key == n && count==1)
			//{
			//	p->next = k;
			//	p = k;
			//}
			k = k->next;
		}

		p->next = NULL;
		//l.pTail = p;
	}
}
void insert_node_before_node(node*& head, node* after, node* insrt)
{
	node* temp = head;
	while (temp->next != after)
	{
		temp = temp->next;
	};
	insrt->next = temp->next;
	temp->next = insrt;
}




void input_list(node*& head, int& n)
{
	int k;
	cout << "Nhap so luong node: "; cin >> n;
	node* temp = head;
	int i = 0;
	while (i < n)
	{
		i++;
		if (head == NULL)
		{
			cout << "value " << i << " : ";
			cin >> k;
			addFirst(head, k);
		}
		else
		{
			cout << "value " << i << " : ";
			cin >> k;
			addTail(head, k);
		}

	}

}
void sort(node*& head)
{
	node* temp = head;
	while (temp != NULL)
	{
		node* temp2 = temp->next;
		while (temp2 != NULL)
		{
			if (temp->key > temp2->key)
			{
				int data;
				data = temp->key;
				temp->key = temp2->key;
				temp2->key = data;
			}
			temp2 = temp2->next;
		}
		temp = temp->next;
	}

}

void    output_list(node* head)
{
	if (head == NULL)
		cout << "Danh sach trong " << endl;
	else

		for (node* i = head; i; i = i->next)
		{
			cout << i->key << "  ";
		}
}

int main()
{
	node* head;
	int n = 0;
	int key;
	init(head);
	input_list(head, n);
	sort(head);
	output_list(head);
	return 0;
}