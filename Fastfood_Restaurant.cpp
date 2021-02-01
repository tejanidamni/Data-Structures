#include <iostream>
#include <deque>
using namespace std;

struct basic_info {
    int arrival_time;
    int ordering_time;
    int wait_affordable;
    
    basic_info(int A, int O, int W) {
        arrival_time = A;
        ordering_time = O;
        wait_affordable = W;
    }
};

int main() {
    int total_customers;
    while (cin >> total_customers)
    {
        deque <basic_info> my_customers;
        int time_passed;
        for (int a = 0; a < total_customers - 1; a++)
        {
            int arr_time;
            int ord_time;
            int wait_aff;
            cin >> arr_time;
            cin >> ord_time;
            cin >> wait_aff;
            basic_info z = basic_info(arr_time, ord_time, wait_aff);
            
            if (a == 0){
                my_customers.push_back(z);
                continue;
            }
            
            time_passed = arr_time;
            basic_info front = my_customers.front();
            
            while (my_customers.empty()==false && time_passed >= front.arrival_time + front.ordering_time){
                my_customers.pop_front();
                front = my_customers.front();
            }
            
            if (not (z.wait_affordable < my_customers.size())){
                if (my_customers.empty()==false){
                    if (z.arrival_time < my_customers.back().arrival_time + my_customers.back().ordering_time){
                        z.arrival_time = my_customers.back().arrival_time + my_customers.back().ordering_time;
                    }
                }
                my_customers.push_back(z);
            }
            
        }
        
        int arr_time;
        int wait_aff;
        int ord_time;
        
        cin >> arr_time;
        cin >> ord_time;
        cin >> wait_aff;
        basic_info z = basic_info(arr_time, ord_time, wait_aff);
        time_passed = arr_time ;
        
        if (total_customers == 1){
            cout << z.arrival_time << endl;
            continue;
        }
        
        basic_info front = my_customers.front();
        
        while (my_customers.empty()==false and time_passed >= front.arrival_time + front.ordering_time){
            my_customers.pop_front();
            front = my_customers.front();
        }
        
        if (z.wait_affordable < my_customers.size()){
            cout << "-1" << endl;
        }else{
            if ((my_customers.back().arrival_time + my_customers.back().ordering_time) > z.arrival_time){
                cout << my_customers.back().arrival_time + my_customers.back().ordering_time << endl;
            }else{
                cout << z.arrival_time << endl;
            }
        }
        
    }
}