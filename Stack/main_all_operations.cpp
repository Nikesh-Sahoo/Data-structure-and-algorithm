//Stack with array 

/** 
#include <iostream>
#include<stdlib.h>
using namespace std;
#define MAX 5
int st[MAX], top=1;
void push(int st[],int val){
    if(top==MAX-1){
        cout<<"Overflow";
    }
    else{
        top++;
        st[top]=val;
    }
}

int pop(int st[]){
    int val;
    if(top==1){
        cout<<"Underflow";
        return -1;
    }
    else{
        top--;
        val=st[top];
        return val;
    }
}

int peek(int st[]){
    if(top==-1){
        cout<<"Stack is empty";
        return -1;
    }
    else{
        return st[top];
    }
}

void display(int st[]){
    int i;
    if(top == -1){
        cout<<"Stack is empty";
    }
    else{
        for(i=top;i>=0;i--){
            cout<<"\n"<<st[i];
        }
    }
}

int main()
{
    int option,val;
    do{
        cout<<"\n1. Push";
        cout<<"\n2. Pop";
        cout<<"\n3. Peek";
        cout<<"\n4. Display";
        cout<<"\n5. Exit";
        cout<<"\nEnter your choice";
        cin>>option;
        switch(option){
        case 1: cout<<"Enter data";
                cin>>val;
                push(st,val);
                break;
        case 2: val=pop(st);
                if(val == -1){
                    cout<<"value deleted:"<<val;
                }
                break;
        case 3: val=peek(st);
                if(val == -1){
                    cout<<"value at top:"<<val;
                }
                break;
        case 4: display(st);
                break;
        }
    }while(option!=5);
    return 0;
}

*/

//Stack with linkedlist

#include <iostream>
#include <stdlib.h>
using namespace std;

struct node {
    int data;
    struct node *next;
}*top,*top1,*temp;

int count = 0;

void push(int data) {
     if (top == NULL)
    {
        top =new node();
        top->next = NULL;
        top->data = data;
    }
    else
    {
        temp =new node();
        temp->next = top;
        temp->data = data;
        top = temp;
    }
    count++;
    cout<<"Node is Inserted\n";
}

int pop() {
    top1 = top;
    int popped;
    if (top1 == NULL)
    {
        cout<<"\nStack Underflow\n";
        return -1;
    }
    else{
        top1 = top1->next;
        popped = top->data;
        free(top);
        top = top1;
        count--;
    }
    return popped;
}

void display() {
    top1 = top;

    if (top1 == NULL)
    {
        cout<<"\nStack Underflow\n";
        return;
    }

    cout<<"The stack is \n";
    while (top1 != NULL)
    {
        cout<<top1->data<<" ";
        top1 = top1->next;
    }
}

int main() {
    int option, val;
    cout<<"\nImplementation of Stack using Linked List\n";
       do{
        cout<<"\n1. Push";
        cout<<"\n2. Pop";
        cout<<"\n3. Display";
        cout<<"\n4. Exit";
        cout<<"\nEnter your choice";
        cin>>option;
        switch(option){
        case 1: cout<<"Enter data";
                cin>>val;
                push(val);
                break;
        case 2: val=pop();
                if(val == -1){
                    cout<<"value deleted:"<<val;
                }
                break;
        case 3: display();
                break;
        }
    }while(option!=4);
return 0;
}

