//singly linked
#include <iostream>
using namespace std;

struct node{
    int data;
    struct node *link;
};

struct node* insert(struct node* head, int data){
        struct node* temp=new node();
        if(head==NULL){
         temp->data=data;
		 temp->link=NULL;
		 head=temp;	
		}
		else{
			temp->data=data;
			temp->link=head;
			head=temp;
		}
	return head;
}

struct node* delele(struct node *head){
	if(head==NULL){
		cout<<"Linked list is empty";
	}
	else{
		struct node* temp=head;
		head=head->link;
		delete temp;
		cout<<"Element deleted";
	}
	return head;
}
struct node* searchele(struct node *head,int search){
	struct node *curr=head;
	int c=0;
    while(curr!=NULL){
    	if(curr->data==search){
    		cout<<"Element found";
    		c=1;
		}
        curr=curr->link;
    }	
    if(c==0){
    	cout<<"Element not found";
	}
}

struct node* traverse(struct node *head){
	struct node* curr=head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->link;
    }
}    

struct node *sort(struct node *head){
	struct node *curr=head;
	struct node *index=NULL;
	int num;
	if (curr==NULL){
		cout<<"Linked list is empty";
	}
	else{
		while(curr!=NULL){
			index = curr->link;
			while(index!=NULL){
				if(curr->data > index->data){
					num = curr->data;  
                    curr->data = index->data;  
                    index->data = num;  
				}
				index=index->link;
			}
			curr=curr->link;
		}
	}
	cout<<"\nLinked List is sorted";
	return head;
}


int main()
{
	struct node* head=NULL;
    int choice=1,data,search;
    do {
        cout << "\nSingly linked list Operations\n";
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



