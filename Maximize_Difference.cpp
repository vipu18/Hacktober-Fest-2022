#include "bits/stdc++.h"
using namespace std;
int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        long long int m;
        cin >> m;
        long long int ans = INT_MIN;
        long long int a, b;
        int c=0;
        for (long long int i = n; i <= m; i++)
        {
            c++;
            a = i;
            b = m - (m % i);
            ans = max(abs(a - b), ans);
            if(c==100000)
            break;
        }
        for (long long int i = n; i <= m; i++)
        {
            a = i;
            b = m - (m % i);
            if (abs(a - b) == ans)
            {
                cout << a << " " << b << endl;
                break;
            }
        }
    }
}
