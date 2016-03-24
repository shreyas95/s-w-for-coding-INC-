#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string temp;
    char *array;
    cin>>temp;
    int j=0;
    int l=temp.length();
    int y;
    if(l%2==0)
    {
        y = l/3-1;
        array = new char[l+y+1];
    }
    else{
        printf("No solution\n");
        return 0;
    }

    for(int i=0;i<l;i+=3)
    {
        char a=temp[i],b=temp[i+1],c=temp[i+2];
        if(a!='@'&&b=='@'&&c!='@')
        {

                array[j]=a;
                array[j+1]=b;
                array[j+2]=c;
                array[j+3]=',';
                j+=4;
        }

    }
    for(int i=0;i<(l+y);i++)
        cout<<array[i];
    cout<<"\n";
    return 0;
}
