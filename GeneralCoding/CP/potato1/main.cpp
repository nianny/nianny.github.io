#include <bits/stdc++.h>
using namespace std;
#define beegspeed ios_base::sync_with_stdio(false);cin.tie(NULL);

string haiz;

int val(char c)
{
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else
        return (int)c - 'A' + 10;
}
 

int toDeci(string str, int base)
{
    int len = str.length();
    int power = 1; 
    int num = 0; 
    int i;
 
    for (i = len - 1; i >= 0; i--)
    {
        if (val(str[i]) >= base)
        {
           return -1;
        }
 
        num += val(str[i]) * power;
        power = power * base;
    }
 
    return num;
}

char reVal(int num)
{
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}

void strev(string str)
{
    int len = str.length();

    for (int i = 0; i < len/2; i++)
    {
        char temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}

string fromDeci(string res, int base, int inputNum)
{
    int index = 0; 

    while (inputNum > 0)
    {
        res[index++] = reVal(inputNum % base);
        inputNum /= base;
    }
    res[index] = '\0';

    strev(res);

    return res;
}



 
int main()
{
    beegspeed
    string p; cin>>p;
    int q,r; cin>>q>>r;
    int temporary=toDeci(p,q);
    cout<<temporary;
    //string ans = fromDeci(haiz,r,temporary);
    //cout<<ans;
    
}
