#include <iostream>
using namespace std;

struct arr
{
    int s, e, m;
};

arr msa_bf(int a[], int n)
{
    arr t;
    t.s = -1;
    t.e = -1;
    t.m = -999;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += a[j];
            if (sum > t.m)
            {
                t.m = sum;
                t.s = i;
                t.e = j;
            }
        }
    }
    return t;
}

int main()
{
    int a[] = {3, -5, 8, -4, 2, -6, 2, 9, -2, 1};
    int n = sizeof(a) / sizeof(a[0]);

    arr r;
    r = msa_bf(a, n);
    cout << "Array is from 0 to " << n - 1 << endl;
    cout << "Start index : " << r.s << endl
         << "End index : " << r.e << endl
         << "Max Sum : " << r.m << endl;
}