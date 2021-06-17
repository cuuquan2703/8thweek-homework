#include<iostream>
using namespace std;
struct Phim {
	char maso[10]; // mã số, Ex. 123456789
	char tenPhim[30]; // tên phim: Before Sunrise, Bo gia
	char nhaSX [30]; // nhà sản xuất, ex. HBO, Phim Giai Phong
	int namSX; // 1975, 2000, 2020
	float XepHang; // 8, 9.2, trong khoang (1,10)
};
struct node
{
	Phim key;
	node* next;
};

void init(node*& head)
{
	head = NULL;
}

void input_phim(Phim& data)
{
	cin.ignore();
	cout << "Ma so: "; cin.getline(data.maso, 30);
	//cin.ignore();
	cout << "Ten phim: "; cin.getline(data.tenPhim, 10);
	//cin.ignore();
	cout << "Nha SX: "; cin.getline(data.nhaSX, 30);
	//cin.ignore();
	cout << "Nam san xuat: ", cin >> data.namSX;
	cout << "Xep Hang : "; cin >> data.XepHang;
}

node* getnode(Phim data)
{
	node* k;
	k = new node;
	k->key = data;
	k->next = NULL;
	return k;
}
void addFirst(node*& head, Phim k)
{
	node* p = getnode(k);
	if (head == NULL)
		head = p;
	else {
		p->next = head;
		head = p;
	}
}
void addTail(node*& head, Phim k)
{
	node* temp = head;
	node* q = getnode(k);
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = q;
}
void deletenode(node*& head, char key[30] )
{
	node** deleteitem = &head;
	node* target = head;
	while (strcmp((*deleteitem)->key.nhaSX, key) != 0)
	{
		deleteitem = &((*deleteitem)->next);
		if (strcmp((*deleteitem)->key.nhaSX, key) == 0)
			target = (*deleteitem);
	}
	(*deleteitem) = target->next;
	delete target;
}
void insert_node_before_node(node*& head, node* after,node* insrt)
{
	node* temp = head;
	while (temp ->next != after)
	{
		temp = temp->next;
	};
	insrt->next = temp->next;
	temp->next = insrt;
}

void insrt_phim(node*& head, Phim n)
{
	node* temp = head;
	//input_phim(n);
	node* k = getnode(n);
	while (temp->key.namSX < n.namSX)
		temp = temp->next;
	insert_node_before_node(head, temp, k);
}

void delete_phim(node*& head,char n[30])
{
	//char n[30] = "HBO";
	for (node* temp=head;temp;temp = temp->next)
	
		if (strcmp(temp->key.nhaSX, n) == 0) deletenode(head, n);
		
	
}

void input_list_phim(node*& head, int& n)
{
	Phim k;
	cout << "Nhap so luong phim: "; cin >> n;
	init(head);
	node* temp = head;
	int i = 0;
	while (i < n)
	{
		i++;
		if (head == NULL)
		{
			cout << "Phim " << i << " : " << endl;
			input_phim(k);
			addFirst(head, k);
		}
		else
		{
			cout << "Phim " << i << " : " << endl;
			input_phim(k);
			addTail(head, k);
		}

	}

}

void    output_list_phim(node* head)
{
	if (head == NULL)
		cout << "Danh sach trong:" << endl;
	else

		for (node* i = head; i; i = i->next)
		{
			cout << endl;
			cout <<"Maso:"<< i->key.maso << endl;
			cout <<"Ten Phim: "<< i->key.tenPhim << endl;
			cout <<"Nam SX: " <<i->key.namSX << endl;
			cout <<"Nha SX: "<< i->key.nhaSX << endl;
			cout <<"Xep Hang:"<< i->key.XepHang << endl;
			cout << endl;
		}
}

int main()
{
	Phim data,k;
	int n = 0;
	node* head = NULL;
	cout << "---------------------" << endl;
	input_list_phim(head, n);
	output_list_phim(head);
	cout<<"-----------------------" << endl;
	cout << "Nhap phim can them: " << endl;
	input_phim(k);
	insrt_phim(head,k);
	output_list_phim(head);
	cout << "--------------------------" << endl;
	char a[30] = "HBO";
	delete_phim(head,a);
	output_list_phim(head);
	cout << "------------------------------" << endl;
	cout << endl;
	
	return 0;
}