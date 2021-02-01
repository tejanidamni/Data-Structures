#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
    int no_of_cases;
    cin >> no_of_cases;

    for (int k = 0; k < no_of_cases; k++){
        long long unsigned int customer;
        long long unsigned int room;

        cin >> room >> customer;
        long long unsigned int* my_rooms = new long long unsigned int[room];
        long long unsigned int m = 0;
        for (m = 0; m < room; m++)
            cin >> my_rooms[m];
        
        sort(my_rooms, my_rooms + room);
        
        long long unsigned int highest = my_rooms[room - 1];
        long long unsigned int middle = 0;
        long long unsigned int lowest = my_rooms[0];
        long long unsigned int my_distance = 0;
      
        while (lowest < highest)
        {
            middle = (lowest + highest) / 2;
            long long unsigned int my_count = 1;
            long long unsigned int beginning = my_rooms[0];
            
            for (m = 1; m < room; m++)
            {
                if (my_rooms[m] - beginning >= middle)
                {
                    my_count++;
                    beginning = my_rooms[m];
                    if (my_count == customer)
                        break;
                }
            }
            if (my_count == customer)
            {
                my_distance = max(my_distance, middle);
                lowest = middle + 1;
            }
            else
            {
                highest = middle;
            }
        }
        cout << my_distance << endl;

    }
}