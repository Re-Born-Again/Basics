#include <iostream>
using namespace std;

struct arr
{
    int s, e, m;
};
arr mcsa(int a[], int l, int m, int h)
{
    int lmax = m;
    int lsum = a[m];
    int sum = a[m];
    for (int i = m - 1; i >= l; i--)
    {
        sum += a[i];
        if (sum > lsum)
        {
            lsum = sum;
            lmax = i;
        }
    }
    int rmax = m + 1;
    int rsum = a[m + 1];
    sum = a[m + 1];
    for (int i = m + 2; i <= h; i++)
    {
        sum += a[i];
        if (sum > rsum)
        {
            rsum = sum;
            rmax = i;
        }
    }

    arr t;
    t.s = lmax;
    t.e = rmax;
    t.m = lsum + rsum;

    return t;
}
arr msa_dc(int a[], int l, int h)
{
    arr t;
    if (l == h)
    {
        t.e = l;
        t.s = l;
        t.m = a[l];
        return t;
    }
    int m = (l + h) / 2;
    arr sa1 = msa_dc(a, l, m);
    arr sa2 = msa_dc(a, m + 1, h);
    arr sa3 = mcsa(a, l, m, h);
    arr msa = (sa1.m > sa2.m && sa1.m > sa3.m) ? sa1 : (sa2.m > sa3.m) ? sa2
                                                                       : sa3;
    return msa;
}

int main()
{
    int a[] = {-1, 3, -2, 5};
    int n = sizeof(a) / sizeof(a[0]);

    arr r;
    r = msa_dc(a, 0, n - 1);
    cout << "Array is from 0 to " << n - 1 << endl;
    cout << "Start index : " << r.s << endl
         << "End index : " << r.e << endl
         << "Max Sum : " << r.m << endl;
}