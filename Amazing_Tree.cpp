#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    string Str;
    while (cin >> Str)
    {
        int output = 0;
        stack<int> Bracket;

        for (int m = 0; m < Str.length(); m++){
            if (Str[m] == '('){
                Bracket.push(m);
            } else {
                int temporary = 1 + (m - Bracket.top()) / 2;
                output = output ^ temporary;
                Bracket.pop();
            }
        }
        cout << output << endl;
    }
    return 0;
}