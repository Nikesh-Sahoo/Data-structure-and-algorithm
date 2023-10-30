#include <iostream>
using namespace std;

class Heap
{
private:
  int arr[100];
  int size = 0;

public:
  void insertion(int val)
  {
    arr[size++] = val;
    int i = size - 1;
    while (i > 0 && arr[i] < (arr[i - 1] / 2))
    {
      swap(arr[i], arr[i - 1]);
      i = (i - 1) / 2;
    }
  }

  void print()
  {
    for (int i = 0; i < size; i++)
    {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
  void setdata()
  {
    for (int i = 0; i < n; i++)
    {
    }
  }
};

int main()
{
  Heap heap;
  int value;
  cout << "Enter the value to be inserted: ";
  cin >> value;
  heap.insertion(value);
  heap.print();
  return 0;
}