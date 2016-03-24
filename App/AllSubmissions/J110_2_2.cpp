#include <iostream>

using namespace std;

inline bool PowerOfTwo(int a)
{
    while((a & 1) != 1)
        a = a >> 1;
    if((a | 1) > 1)
        return false;
    else return true;
}

int main()
{
    long int t, n, maxv = 0, one = 1;
    cin >> t;
    while(t != 0)
    {
        cin >> n;
        maxv = n;
        if (n == 1)
        {
            cout << one;
            continue;
        }
        while(!PowerOfTwo(n))
        {
            if(n%2 == 1)
                n = 3*n + 1;
            else
                n = n/2;
            if(maxv < n)
                maxv = n;
        }
        cout << maxv << endl;
        t--;
    }

    return 0;
}
