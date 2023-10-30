#include<iostream>
using namespace std;
#define MAX_SIZE 50

class Heap
{
private:
    int arr[MAX_SIZE]; 
public:
    int size=0; 
 
    void insert(int val)
    {
         arr[size++] = val; 

        int i = size - 1;
        while (i > 0 && arr[i] > arr[(i-1)/2])
        {
            swap(arr[i], arr[(i-1)/2]);
            i = (i-1)/2;
        }
    }
    void search(int sele)
    {
    	int c=0;
        for (int i = 0; i < size; i++)
        {
        	if(arr[i]==sele){
        		cout<<"Element found";
        		c=1;
        		break;
			}
        }
        if(c==0){
        cout<<"Element not found.";	
		}
    }
};

int main()
{
    Heap h;
    int choice=1, val, sele;
    while(choice==1){
    cout<<"Enter the value to be inserted:"<<endl;
    cin>>val;
    h.insert(val);
    cout<<"Do you want to continue:";
    cin>>choice;
    }
    cout<<"Enter the value you want to search:";
    cin>>sele;
    h.search(sele);
    return 0;
}
