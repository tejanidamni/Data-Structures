#include<iostream>
#include<stack>
using namespace std;

int main() {
    int no_of_cases;
    cin >> no_of_cases;
    for (int a = 0; a < no_of_cases; a++)
    {
        int no_of_days;
        cin >> no_of_days;
        long long int * my_array=new long long int[no_of_days];
        stack <long long int> my_stocks;
        long long int my_area = 0;
        long long int my_maximum_area = 0;
        long long int my_top = 0;
        int i = 0;
        for (i = 0; i < no_of_days; i++)
        {
            int my_price;
            cin >> my_price;
            my_array[i] = my_price;
        }
        for (i = 0; i < no_of_days;)
        {
            if (my_stocks.empty()==true or my_array[my_stocks.top()] <= my_array[i]){
                my_stocks.push(i++);
            }else {
                my_top = my_stocks.top();
                my_stocks.pop();
                if (my_stocks.empty()==true){
                    my_area = (my_array[my_top]) * i;
                }else{
                    my_area = (my_array[my_top]) * (i - my_stocks.top() - 1);
                }
                if (my_maximum_area < my_area){
                    my_maximum_area = my_area;
                }
            }
        }
        while (my_stocks.empty()==false)
        {
            my_top = my_stocks.top();
            my_stocks.pop();
            if (my_stocks.empty()==true){
                my_area = my_array[my_top] * i;
            }else{
                my_area = (my_array[my_top]) * (i - my_stocks.top() );
            }
            
            if (my_maximum_area < my_area){
                my_maximum_area = my_area;
            }
        }
        cout << my_maximum_area << endl;
    }
}