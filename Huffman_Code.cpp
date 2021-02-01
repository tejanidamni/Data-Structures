#include <iostream>
#include <queue>
using namespace std;

struct element {
    int label;
    int frequency;
    
    element(int a, int b) {
        label = a;
        frequency = b;
    }
};

bool operator<(const element& x, const element& y) {
    return x.frequency > y.frequency;
}

int My_Tree[2*100000][3];

int get_weight(int I, int W)
{
    if (My_Tree[I][1] == -1)
        return W * My_Tree[I][0];
    else
        return get_weight(My_Tree[I][1], W + 1) + get_weight(My_Tree[I][2], W + 1);
}

int main()
{
    int number_element;
    while (cin >> number_element)
    {
        priority_queue<element> priority_queue;
        int Nodes = number_element;
        for (int i = 0; i < number_element; i++)
        {
            int temp;
            cin >> temp;
            priority_queue.push(element(i, temp));
            
            My_Tree[i][0] = temp;
            My_Tree[i][1] = -1;
            My_Tree[i][2] = -1;
        }
        while(true)
        {
            element first = priority_queue.top();
            priority_queue.pop();
            
            if (priority_queue.empty())
                break;
            
            element second = priority_queue.top();
            priority_queue.pop();
            
            priority_queue.push(element(Nodes, first.frequency + second.frequency));
            My_Tree[Nodes][0] = first.frequency + second.frequency;
            My_Tree[Nodes][1] = first.label;
            My_Tree[Nodes++][2] = second.label;
        }
        cout << get_weight(Nodes - 1, 0) << endl;
    }
    return 0;
}