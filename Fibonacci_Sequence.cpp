#include <iostream>
#include <algorithm>
using namespace std;

void count_sorting(long int* array, long int n,long int move)
{
    long int* count1 = new long int[4096];

    for (int i = 0; i < 4096; i++){
        count1[i] = 0;
    }

    long int * output1 = new long int[n];
    long int j, last;
    for (j = 0; j < n; j++)
    {
        ++count1[(array[j] >> move) & 4095];
    }
    for (j = last = 0; j < 4096; j++)
    {
        last += count1[j];
        count1[j] = last - count1[j];
    }
    for (j = 0; j < n; j++)
    {
        output1[count1[(array[j] >> move) & 4095]++] = array[j];
    }
    for (j = 0; j < n; j++)
    {
        array[j] = output1[j];
    }
    delete output1;
    delete count1;
}

int main()
{
    int no_of_cases;
    cin >> no_of_cases;
    for (int i=0; i<no_of_cases; i++)
    {
        long int n,q;

        cin >> n;
        cin >> q;

        long int s = 1;
        long int f = 0;
        long int fib = 0;

        long int * array1 = new long int[n];

        array1[0] = s;
        long int a = 0;
        for (long int j = 1; j < n; j++)
        {
            fib = (f + s) % q;
            f = s;
            s = fib;
            array1[j] = fib;

            if (a < array1[j]){
                a = array1[j];
            }
        }

        for (long int move = 0; a > 0; move += 12)
        {
            count_sorting(array1, n, move);
            a >>= move;
        }

        long long int sum1 = 0;

        for (long long int k = 0; k < n; k++)
        {
            sum1 = sum1 + ((k + 1) * array1[k]) % q;
        }

        delete array1;

        sum1 = sum1 % q;

        cout << sum1 << endl;
    }
}