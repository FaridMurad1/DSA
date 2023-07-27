#include<bits/stdc++.h>
using namespace std;
void ovr(char a[],int n)
{
    int j=0;
    while(n>0)
    {
        int bit=n&1;
        if(bit)
        {
            cout<<a[j];
        }
        j++;
        n>>=1;
    }
    cout<<endl;
}
void chk(char a[])
{
    int n=strlen(a);
    for(int i=0;i<pow(2,n);i++)
    {
        ovr(a,i);
    }
}
int main()
{
    char a[1000];
    cin>>a;
    chk(a);
}