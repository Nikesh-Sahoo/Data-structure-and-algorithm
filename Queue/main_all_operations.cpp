#include <iostream>
#include<stdlib.h>
using namespace std;
#define MAX 10
int queuee[MAX];
int frontt = -1, rear = -1;

void enqueue(int val){
if(rear == MAX-1){
    cout<<"Overflow";
}
else if(frontt == -1 && rear == -1 ){
    frontt=rear=0;
}
else{
    rear++;
    queuee[rear]=val;
}
}

int dequeue(){
    int val;
    if(frontt == -1){
        cout<<"Underflow";
        return -1;
}
else{
    frontt++;
    val=queuee[frontt];
    frontt=rear=0;
    return val;
}
}

int peek(){
if(frontt == -1){
    cout<<"Queue is empty";
    return -1;
}
else{
    return queuee[frontt];
}
}

void display(){
int i;
cout<<"\n";
if(frontt == -1){
    cout<<"Queue is empty";
}
else{
    for(i=frontt;i<=rear;i++){
        cout<<"\t"<<queuee[i];
    }
}
}

int main()
{
    int option,val;
    do{
        cout<<"\n1. Insert";
        cout<<"\n2. Delete";
        cout<<"\n3. Peek";
        cout<<"\n4. Display";
        cout<<"\n5. Exit";
        cout<<"\nEnter your choice";
        cin>>option;
        switch(option){
        case 1: cout<<"Enter data";
                cin>>val;
                enqueue(val);
                break;
        case 2: val=dequeue();
                if(val == -1){
                    cout<<"value deleted:"<<val;
                }
                break;
        case 3: val=peek();
                if(val == -1){
                    cout<<"value at front:"<<val;
                }
                break;
        case 4: display();
                break;
        }
    }while(option!=5);
    return 0;
}
