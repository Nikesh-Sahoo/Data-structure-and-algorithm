//circular linked
#include <iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};

struct node* insert(struct node* head, int data){
        struct node* temp=new node();
        temp->data=data;
        if(head==NULL){
		 head=temp;	
		 temp->next=head;
		}
		else{
			struct node *curr=head;
			while(curr->next!=head){
				curr=curr->next;
			}
			curr->next=temp;
			temp->next=head;
		}
	cout<<"\nElement inserted";	
	return head;
}

struct node* delele(struct node *head){
	if(head==NULL){
        cout<<"Linked list is empty";
	}
	else if(head->next==head){
		head=NULL;
		delete head;
		cout<<"Element deleted";
	}
	else{
		struct node *ptr=head;
		while(ptr->next!=head){
			ptr=ptr->next;
		}
		ptr->next=head->next;
		delete head;
		head=ptr->next;
		cout<<"Element deleted";
	}
	return head;
}

struct node* searchele(struct node *head,int search){
	struct node *curr=head;
	int c=0;
    while(curr->next!=head){
    	if(curr->data==search){
    		cout<<"Element found";
    		c=1;
		}
        curr=curr->next;
    }	
    if(c==0){
    	cout<<"Element not found";
	}
}

struct node* traverse(struct node *head){
	struct node* curr=head;
    while(curr->next!=head){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    cout<<curr->data<<" ";
}    

struct node *sort(struct node *head){
	struct node *curr=head;
	struct node *index=NULL;
	int num;
	if (curr==NULL){
		cout<<"Linked list is empty";
	}
	else{
		do{
			index = curr->next;
			while(index->next!=head){
			if(curr->data > index->data){
				num = curr->data;  
                curr->data = index->data;  
                index->data = num;  
			}
			index=index->next;
			}
		curr=curr->next;	
		}while(curr->next!=head);		
	}
	cout<<"\nLinked List is sorted";
	return head;
}


int main()
{
	struct node* head=NULL;
    int choice=1,data,search;
    do {
        cout << "\nDoubly linked list Operations\n";
        cout << "-----------------------------\n";
        cout << "1. Insert Node\n";
        cout << "2. Search Node\n";
        cout << "3. Delete a Node\n";
        cout << "4. Traverse\n";
        cout << "5. Sort\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

    switch(choice){
    	case 1:	cout<<"\n Enter data into nodes:";
				cin>>data;
				head = insert(head,data);
				break;
		case 2:	cout<<"\n Enter element to search:";
				cin>>search;
				searchele(head,search);
				break;	
		case 3:	head = delele(head);
				break;	
		case 4:	traverse(head);
				break;			
		case 5: head = sort(head);
		        break;						
	}
	}while(choice!=6);
    return 0;
}



