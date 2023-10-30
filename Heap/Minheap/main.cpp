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

       void deleteRoot()
    {
        
        arr[0] = arr[--size]; 
        int i = 0;


        while (2*i+1 < size)
        {
            int left = 2*i+1, right = 2*i+2;
           int max_child;
            if (right < size && arr[right] > arr[left]) {
                           max_child = right; 
                           
           } else {
               max_child = left;
               }

            if (arr[i] < arr[max_child])
            {
                swap(arr[i], arr[max_child]);
                i = max_child;
            }
            else
            {
                break;
            }
        }
    }

    void traverse()
    {
        for (int i = 0; i < size; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    Heap h;

    int choice, val;

    do {
        cout<<"Enter your choice:"<<endl;
        cout<<"1. Insert"<<endl;
        cout<<"2. Delete Root"<<endl;
        cout<<"3. Traverse"<<endl;
        cout<<"4. Exit"<<endl;
        cin>>choice;

        switch (choice)
        {
            case 1:
                cout<<"Enter the value to be inserted:"<<endl;
                cin>>val;
                h.insert(val);
                break;

            case 2:
                h.deleteRoot();
                break;

            case 3:
                cout<<"Heap elements in level order:"<<endl;
                h.traverse();
                break;

            case 4:
                cout<<"Exit..."<<endl;
                break;

            default:
                cout<<"Invalid choice"<<endl;
        }

    } while (choice != 4);

    return 0;
}
