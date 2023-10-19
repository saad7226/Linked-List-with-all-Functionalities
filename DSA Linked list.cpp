#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node *next;
		
		Node(int data)
		{
			this->data=data;
			next=NULL;
		}
};

void Initialized_emptylist(Node* &head)
{
	head=NULL;
	cout<<"Empty list is initialized "<<endl;
}

void Add_at_beginning(Node* &head,int value)
{
	Node*temp=new Node(value);
	if(head==NULL)
	{
		head=temp;
		return;
	}
	temp->next=head;
	head=temp;
}

void Add_at_end(Node* head,int value)
{
	Node*temp=new Node(value);
	if(head==NULL)
	{
		head=temp;
		return;
	}
	
	Node* current=head;
	while(current->next!=NULL)
	{
		current=current->next;
	}
	current->next=temp;
}

void Add_at_specific_location(Node*head,int value,int position)
{
	
	
	Node* temp=new Node(value);
	if(position==0 || head==NULL)
	{
		Add_at_beginning(head, value);
		return;
	}
	
	Node* pervious=head;
	for(int i=0;i<position-1;i++)
	{
		pervious=pervious->next;
	}
	temp->next=pervious->next;
	pervious->next=temp;	
}

void Delete(Node* &head,int position)
{
	if(head==NULL)
	{
		return;
	}
	Node*temp=head;
	if(position==0)
	{
		head=head->next;
		temp->next=NULL;
		delete temp;
		return;
	}

	Node*current=head;
	Node*pervious=NULL;
	for(int i=0;i<position;i++)
	{
		pervious=current;
		current=current->next;
	}
	pervious->next=current->next;
	current->next=NULL;
			
}

void Display(Node* head)
{
	Node* current=head;
	while(current!=NULL)
	{
		cout<<current->data<<" "<<"-> ";
		current=current->next;
	}
	cout<<"NULL ";
	cout<<endl;
}

bool Search_specific_node(Node* head,int value)
{
	Node* current=head;
	while(current!=NULL)
	{
		if(current->data==value)
		{
			cout<<"Specfic node exist in this linked list "<<endl;
			return true;
		}
		current=current->next;
	}
	cout<<"Specfic node doesnot exist in this linked list "<<endl;
	return false;
}

void Transverse_linkedlist(Node* head)
{
	Node* current=head;
	while(current!=NULL)
	{
		cout<<current->data<<" "<<"-> ";
		current=current->next;
	}
	cout<<"NULL ";
	cout<<endl;
}

void sorting_linkedlist(Node* head)
{
	Node* slow=head;
	Node* fast=slow->next;
	while(slow!=NULL)
	{
		while(fast!=NULL)
		{
			if(slow->data>fast->data)
			{
				int temp=slow->data;
				slow->data=fast->data;
				fast->data=temp;
			}
			fast=fast->next;
		}
		slow=slow->next;
	}
}

int main()
{
	int number,value,position;
	char yes_or_no;
	Node* head=NULL;
		
	cout<<"Enter 1 for 1. Initialize an empty linked list."<<endl;
	cout<<"Enter 2 for Insert a node at the beginning of the linked list."<<endl;
	cout<<"Enter 3 for Insert a node at the end of the linked list."<<endl;
	cout<<"Enter 4 for Insert a node at a given position in the linked list."<<endl;
	cout<<"Enter 5 for Delete a node from the linked list."<<endl;
	cout<<"Enter 6 for Print the elements of the linked list."<<endl;
	cout<<"Enter 7 for Search a specific node in the linked list."<<endl;
	cout<<"Enter 8 for Traverse."<<endl;
	cout<<"Enter 9 for Sorting."<<endl;
	cout<<endl;
	
	
	do
	{
		cout<<"From above Menu Choose your desired operations ";
		cin>>number;
		switch(number)
		{
			case 1:
				Initialized_emptylist(head);
				break;
			case 2:
				cout<<"Enter value to insert at head position "<<endl;
				cin>>value;
				Add_at_beginning(head,value);
				break;
			case 3:
				cout<<"Enter value to insert at tail position"<<endl;
				cin>>value;
				Add_at_end(head,value);
				break;
			case 4:
				cout<<"Enter value you want to insert "<<endl;
				cin>>value;
				cout<<"Enter position at where you want to add new node"<<endl;
				cin>>position;
				Add_at_specific_location(head,value,position);
				break;
			case 5:
				cout<<"Enter position of node which  you want to delete"<<endl;
				cin>>position;
				Delete(head,position);
				break;
			case 6:
				Display(head);
				break;
			case 7:
				cout<<"Enter value to search the node"<<endl;
				cin>>value;
				Search_specific_node(head,value);
				break;
			case 8:
				Transverse_linkedlist(head);
				break;
			case 9:
				sorting_linkedlist(head);
				Display(head);	
				
		}
		
		cout<<"Do you want to continue if yes enter y otherwise enter  n"<<endl;
		cin>>yes_or_no;
	}while(yes_or_no!='n');
	
	return 0;
}
