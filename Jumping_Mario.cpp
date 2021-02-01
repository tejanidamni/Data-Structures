#include <iostream>

using namespace std;

int main() {
    int no_of_cases;
    cin >> no_of_cases;
    for (int i = 0; i < no_of_cases; i++)
    {
        int no_of_walls;
        cin >> no_of_walls;
        int higher_wall = 0, smaller_wall = 0;
        int previous_wall;
        cin >> previous_wall;
        for (int j = 1; j < no_of_walls; j++)
        {
            int height_of_walls;
            cin >> height_of_walls;
            if (height_of_walls > previous_wall){
                higher_wall=higher_wall+1;
            }
            else if (previous_wall > height_of_walls){
                smaller_wall=smaller_wall+1;
            }

            previous_wall = height_of_walls;
        }
        cout << "Case " << i + 1 << ": " << higher_wall << " " << smaller_wall << endl;
    }
}