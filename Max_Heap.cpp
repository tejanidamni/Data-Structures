#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int my_heap[100001] = { -1 };

int my_pointer;
long long int summation;

void Insert()
{
    cin >> my_heap[my_pointer];
    summation = summation + my_heap[my_pointer];
    int parent = my_pointer / 2;
    int child = my_pointer++;
    while (my_heap[parent] < my_heap[child] and parent)
    {
        int temporary = my_heap[parent];
        my_heap[parent] = my_heap[child];
        my_heap[child] = temporary;
        child = parent;
        parent=parent/ 2;
    }
}

void Pop(){

    summation =summation - my_heap[1];
    my_heap[1] = my_heap[--my_pointer];
    my_heap[my_pointer + 1] = -1;

    int Parent_01 = 1;
    int Child_01 = 2;
    int Child_02 = 3;

    while (my_heap[Parent_01] < max(my_heap[Child_01], my_heap[Child_02])){
        int temporary = my_heap[Parent_01];
        int New_Child;

        if (my_heap[Child_01] >= my_heap[Child_02]){
            New_Child = Child_01;
        }else{
            New_Child = Child_02;
        }
        my_heap[Parent_01] = my_heap[New_Child];
        my_heap[New_Child] = temporary;

        Parent_01 = New_Child;
        Child_01 = Parent_01 * 2;
        Child_02 = Child_01 + 1;
    }
}

int main()
{
    int no_of_operations;
    while (cin >> no_of_operations)
    {
        summation = 0;
        my_pointer = 1;
        memset(my_heap, -1, sizeof(my_heap));
        for(int i=0;i<no_of_operations;i++)
        {
            char operation_name;
            cin >> operation_name;
            if (operation_name == 'a')
                Insert();
            else if (operation_name == 'p')
                Pop();
            else if (operation_name == 'r')
                cout << summation << endl;
        }
    }
    return 0;
}