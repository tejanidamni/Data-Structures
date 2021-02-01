#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node* left_pointer;
    Node* right_pointer;
};

int search(int* arr, int s, int e, int a)
{
    int i;
    
    for ( i = s; i <=e; i++)
    {
        if (arr[i] == a)
        {
            break;
        }
    }
    return i;
}

static int pre_index = 0;

Node* reconstruction(int* in_order, int* pre_order, int start_index, int end_index){
    
    if (start_index > end_index){
        return NULL;
    }
    Node* my_node = new Node();
    
    my_node->value = pre_order[pre_index];
    my_node->right_pointer = NULL;
    my_node->left_pointer = NULL;
    
    
    pre_index++;
    if (start_index == end_index)
        return my_node;
    int in_order_index = search(in_order, start_index, end_index, my_node->value);
    
    my_node->left_pointer = reconstruction(in_order, pre_order, start_index, in_order_index-1);
    my_node->right_pointer = reconstruction(in_order, pre_order, in_order_index + 1, end_index);
    
    return my_node;
}



static int control = 0;
static int gr_size;
static int * my_data;

void post_order(Node* pointer)
{
    
    if (pointer != NULL)
    {
        post_order(pointer->left_pointer);
        post_order(pointer->right_pointer);
        my_data[control++] = pointer->value;
    }
}

int main() {
    int no_of_cases;
    cin >> no_of_cases;
    for (int i = 0; i < no_of_cases; i++)
    {
        int my_size = 0;
        cin >> my_size;
        gr_size = my_size;
        
        my_data = new int(gr_size);
        
        control = 0;
        int* in_order = new int[my_size];
        int* pre_order = new int[my_size];
        
        for (int j = 0; j < my_size; j++)
        {
            int temporary;
            cin >> temporary;
            pre_order[j] = temporary;
        }
        for (int k = 0; k < my_size; k++)
        {
            int temporary;
            cin >> temporary;
            in_order[k] = temporary;
        }
        Node* Root = reconstruction(in_order, pre_order, 0, my_size - 1);
        post_order(Root);
        Root = NULL;
        
        for (int l = 0; l < my_size; l++)
        {
            if (l < my_size - 1){
                cout << my_data[l] << " ";
            }else{
                cout << my_data[l] << endl;
            }
        }
        pre_index = 0;
    }
}