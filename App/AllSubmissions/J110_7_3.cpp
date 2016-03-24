#include <iostream>

using namespace std;

int main()
{
    long int t, p, tmp;
    cin >> t;
    while(t != 0)
    {
        cin >> tmp;
        if(tmp == 1)
        {
            cout << 2 << endl;
            t--;
            continue;
        }
        if(tmp == 2)
        {
            cout << 4 << endl;
            t--;
            continue;
        }
        p = 4;
        tmp = tmp-2;
        p = 4 + (tmp*tmp + 5*tmp)/2;
        cout << p << endl;
        t--;
    }
    return 0;
}
