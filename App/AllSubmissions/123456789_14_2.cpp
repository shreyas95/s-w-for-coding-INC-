
/////////////////
// EdgeCase.cc //
/////////////////

// @EXPECTED_RESULTS@: CORRECT

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
vector<string> c;

string add(string lhs, string rhs)
{
     // convert lhs and rhs to little endian, i.e., least-significant-digit first

    reverse(lhs.begin(), lhs.end());
    reverse(rhs.begin(), rhs.end());

    // make sure lhs and rhs have the same number of digits

    if (lhs.size() < rhs.size())
    {
        lhs.append(rhs.size() - lhs.size(), '0');
    }
    else if (rhs.size() < lhs.size())
    {
        rhs.append(lhs.size() - rhs.size(), '0');
    }

    // lhs += rhs

    unsigned value = 0;

    for (unsigned i = 0; i < lhs.size(); ++i)
    {
        value += (lhs[i] - '0') + (rhs[i] - '0');
        lhs[i] = ('0' + value % 10);
        value /= 10;
    }

    if (value != 0)
    {
        lhs += ('0' + value);
    }

    reverse(lhs.begin(), lhs.end());

    return lhs;
}


void init(){
    c.push_back("1");
    c.push_back("1");
    c.push_back("3");

        while (c.size() <= 1000)  // make sure c is up to the task
        {
            c.push_back(add(c[c.size() - 2], c[c.size() - 1]));
        }
  
}





int main()
{
    // The requested number turns out to be generated by a Fibonacci-like sequence that
    // misbehaves a bit in the beginning:
    //
    // 0 -> 1, 1 -> 1, 2 -> 3, 3 -> 4, 5 -> 7, 6 -> 11, 7 -> 18, 8 -> 29, 9 -> 47, ...
    //
    // NOTE: the value at n == 1 could be argued to be "2", from the problem text.

   init();
    int t,n;
    cin>>t;
while(t--){
	cin>>n;
	cout<<c[n]<<"\n";

}

    return 0;
}