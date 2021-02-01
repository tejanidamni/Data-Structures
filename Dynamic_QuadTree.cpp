#include <math.h>
#include <cstring>
#include <iostream>
using namespace std;

int quadua_tree[1025][1025];
 int A[12][1025 * 1025];
int my_count;

void save_cordinates(int xcordinate1, int ycordinate1, int xcordinate2, int ycordinate2)
{
    if (xcordinate2 - xcordinate1 == 2 and ycordinate2 - ycordinate1 == 2)
    {
        A[0][my_count] = quadua_tree[xcordinate1][ycordinate1];
        quadua_tree[xcordinate1][ycordinate1] = my_count++;
        A[0][my_count] = quadua_tree[xcordinate1][ycordinate1 + 1];
        quadua_tree[xcordinate1][ycordinate1 + 1] = my_count++;
        A[0][my_count] = quadua_tree[xcordinate1 + 1][ycordinate1];
        quadua_tree[xcordinate1 + 1][ycordinate1] = my_count++;
        A[0][my_count] = quadua_tree[xcordinate1 + 1][ycordinate1 + 1];
        quadua_tree[xcordinate1 + 1][ycordinate1 + 1] = my_count++;
    }
    else
    {
        save_cordinates(xcordinate1, ycordinate1, (xcordinate1 + xcordinate2) / 2, (ycordinate1 + ycordinate2) / 2);

        save_cordinates(xcordinate1, (ycordinate1 + ycordinate2) / 2, (xcordinate1 + xcordinate2) / 2, ycordinate2);

        save_cordinates((xcordinate1 + xcordinate2) / 2, ycordinate1, xcordinate2, (ycordinate1 + ycordinate2) / 2);

        save_cordinates((xcordinate1 + xcordinate2) / 2, (ycordinate1 + ycordinate2) / 2, xcordinate2, ycordinate2);

    }
}

int main(){
    int no_of_cases;
    cin >> no_of_cases;
    for (int i = 0; i < no_of_cases; i++){
        int k;
        cin >> k;

        int N = pow(2, k);

        for (int j = 0; j < N; j++){
            for (int i = 0; i < N; i++){
                char bit;
                cin >> bit;

                quadua_tree[j][i] = bit - 48;
            }
        }


        long long int answer = 1;
        int E[12];

        memset(E, 0, sizeof(E));
        my_count = 0;

        if (N == 1){
            A[0][E[0]++] = quadua_tree[0][0];
        }else{
            save_cordinates(0, 0, N, N);
            E[0] = my_count;

            for (int i = 1; i < 12; i++)
            {
                for (int j = 0; j < E[i - 1]; j++)
                {
                    if (A[i - 1][j] == A[i - 1][j + 1] && A[i - 1][j] == A[i - 1][j + 2] && A[i - 1][j] == A[i - 1][j + 3] && A[i - 1][j] != -1)
                        A[i][E[i]++] = A[i - 1][j];
                    else
                    {
                        A[i][E[i]++] = -1;
                        answer += 4;
                    }
                    j += 3;
                }
                if (E[i] == 1){
                    break;
                }
            }
        }

        int operations;
        cin >> operations;
        for (int i = 0; i < operations; i++)
        {
            int row, column;
            cin >> row >> column;
            row=row-1;
            column=column-1;

            int L = quadua_tree[row][column];
            long long int new_value;
            long long int new_answer = answer;
            if (A[0][L] == 1)
                new_value = 0;
            else
                new_value = 1;

            for (int J = 0; J < 12; J++)
            {
                if (E[J] == 1)
                    break;

                if (A[J][L] == new_value)
                    break;

                int new_low = L - L % 4;
                if (A[J][new_low] == A[J][new_low + 1] && A[J][new_low] == A[J][new_low + 2] && A[J][new_low] == A[J][new_low + 3])
                {
                    if (A[J][new_low] != -1)
                        new_answer += 4;
                    A[J][L] = new_value;
                    new_value = -1;
                }
                else
                {
                    A[J][L] = new_value;

                    if (A[J][new_low] == A[J][new_low + 1] && A[J][new_low] == A[J][new_low + 2] && A[J][new_low] == A[J][new_low + 3]){
                        if (new_value != -1){
                            new_answer -= 4;
                        }
                    }else{
                        new_value = -1;
                    }
                }
                L /= 4;
            }
            answer = new_answer;
            cout << new_answer << endl;
        }
    }
    return 0;
}