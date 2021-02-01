#include <iostream>
#include <queue>
using namespace std;

struct my_task {
    int arrival_time;
    int processing_time;
    int index_value;
    
    my_task(int arr, int proc, int index) {
        arrival_time = arr;
        processing_time = proc;
        index_value = index;
    }
};

int main() {
    int no_of_tasks;
    while (cin >> no_of_tasks){
        queue<my_task> low_priority;
        queue<my_task> high_priority;
        int answer[100];
        for (int a = 0; a < no_of_tasks; a++)
        {
            int arr_time, proc_time, priority_level;
            cin >> arr_time >> proc_time >> priority_level;
            if (priority_level>0)
            {
                low_priority.push(my_task(arr_time, proc_time, a));
            }
            else
            {
                high_priority.push(my_task(arr_time, proc_time, a));
            }
        }
        int my_time = 0;
        while (low_priority.empty()==false) {
            my_task l = low_priority.front();
            my_task hop(-1, -1, -1);
            if (high_priority.empty()==false){
                hop = high_priority.front();
            }
            else{
                while (low_priority.empty()==false){
                    my_task l = low_priority.front();
                    if (my_time < l.arrival_time){
                        my_time = l.arrival_time;
                    }
                    my_time =my_time+ l.processing_time;
                    answer[l.index_value] = my_time;
                    low_priority.pop();
                }
                break;
            }
            if (hop.arrival_time <= l.arrival_time || hop.arrival_time <= my_time){
                if (my_time < hop.arrival_time){
                    my_time = hop.arrival_time;
                }
                my_time =my_time+ hop.processing_time;
                answer[hop.index_value] = my_time;
                high_priority.pop();
            }else{
                if (my_time < l.arrival_time){
                    my_time = l.arrival_time;
                }
                my_time = my_time + l.processing_time;
                answer[l.index_value] = my_time;
                low_priority.pop();
            }
        }
        while (not high_priority.empty())
        {
            my_task hop = high_priority.front();
            if (my_time < hop.arrival_time)
            {
                my_time = hop.arrival_time;
            }
            my_time = my_time + hop.processing_time;
            answer[hop.index_value] = my_time;
            high_priority.pop();
        }
        cout << answer[0];
        for (int k = 1; k < no_of_tasks; k++)
        {
            cout << " " << answer[k];
        }
        cout << endl;
    }
}