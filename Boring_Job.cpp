#include <iostream>
#include <queue>
using namespace std;

struct block {
    int index;
    int value;
    
    block(int pos, int val) {
        index = pos;
        value = val;
    }
    
    block() {
        index = 0;
        value = -1000;
    }
    
    void reduce_value() {
        value=value-1;
    }
};

block get_greatest_one(queue <block> random) {
    block big;
    while (!random.empty())
    {
        if (random.front().value > big.value)
        {
            big = random.front();
        }
        random.pop();
    }
    return big;
}

int main() {
    int no_of_cases;
    cin >> no_of_cases;
    for (int i = 0; i < no_of_cases; i++)
    {
        int length;
        
        int magic_number;
        
        cin >> length;
        
        cin >> magic_number;
        
        queue <block> my_S;
        
        for (int j = 1; j <= length; j++)
        {
            int temporary;
            cin >> temporary;
            block my_tmp(j, temporary);
            my_S.push(my_tmp);
        }
        
        while (my_S.size() >= magic_number)
        {
            queue <block> temp_queue;
            
            for (int j = 0; j < magic_number; j++)
            {
                temp_queue.push(my_S.front());
                my_S.pop();
            }
            
            block largest = get_greatest_one(temp_queue);
            
            cout << largest.index;
            
            length=length-1;
            
            if (length>0){
                cout << " ";
            }
            
            while (temp_queue.empty()==false){
                if (largest.index != temp_queue.front().index){
                    temp_queue.front().reduce_value();
                    my_S.push(temp_queue.front());
                }
                temp_queue.pop();
            }
        }
        
        
        while (my_S.empty()==false){
            
            queue <block> temp_queue;
            
            while (not my_S.empty()){
                temp_queue.push(my_S.front());
                my_S.pop();
            }
            
            block largest = get_greatest_one(temp_queue);
            
            cout << largest.index;
            
            length=length-1;
            
            if (length>0){
                cout << " ";
            }
            
            while (temp_queue.empty()==false){
                if (largest.index != temp_queue.front().index){
                    
                    temp_queue.front().reduce_value();
                    
                    my_S.push(temp_queue.front());
                }
                temp_queue.pop();
            }
        }
        cout << endl;
    }
    return 0;
}