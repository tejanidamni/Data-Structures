#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    string Str;
    while (getline(cin, Str))
    {
        stack<int> reverse_polish_notation;
        int z = 0;
        while (Str[z] != '\0')
        {
            if (Str[z] == ' ')
            {
                z++;
                continue;
            }
            if (Str[z] == '+')
            {
                int one = reverse_polish_notation.top();
                reverse_polish_notation.pop();
                int two = reverse_polish_notation.top();
                reverse_polish_notation.pop();
                reverse_polish_notation.push(one + two);
            }
            else if (Str[z] == '-') {
                int one = reverse_polish_notation.top();
                reverse_polish_notation.pop();
                int two = reverse_polish_notation.top();
                reverse_polish_notation.pop();
                reverse_polish_notation.push(two - one);
            }
            else if (Str[z] == '*'){
                int one = reverse_polish_notation.top();
                reverse_polish_notation.pop();
                int two = reverse_polish_notation.top();
                reverse_polish_notation.pop();
                reverse_polish_notation.push(one * two);
            }else{
                reverse_polish_notation.push(Str[z] - '0');
            }

            z++;
        }
        cout << reverse_polish_notation.top() << endl;


    }
}