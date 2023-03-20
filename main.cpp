#include <bits/stdc++.h>

using namespace std;


int degree (char c)
{
    if (c == '^' )return 5;
    if (c == '*' || c == '/') return 4;
    if (c == '+' || c == '-' ) return 3;
    return 2 ;
}


void Solve ()
{
    string s;
    cout<<"nhap s"<<endl;
    cin>>s;
    string res = "";
    stack <char> stk;
    for (int i = 0; i <s.size(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')res += s[i];
        else if (s[i] >= 'a' && s[i] <= 'z')res += s[i];
        else if (s[i] == '(') stk.push(s[i]);
        else if (s[i] == ')') 
        {
            while (stk.size() && stk.top() != '(')
            {
                res += stk.top();
                stk.pop();
            }
            stk.pop();
            
        }else if (s[i] == '+'||s[i]=='-'||s[i]=='/'||s[i]=='*'||s[i]=='^')
        {
            if (stk.size() == 0)
            {
                stk.push(s[i]);
                
            }else{
                
                if (stk.size()&& degree(s[i]) <= degree(stk.top())) // khac voi youtube khong dung vong while cho cau lenh nay
                {
                    res+=stk.top();
                    stk.pop();

                }
                stk.push(s[i]);
            }
        }
    }
    while (stk.size())
    {
        if (stk.top() != '(')
        res += stk.top();
        stk.pop();
    }

    cout<<res<<endl;

}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        Solve();
    }
    
    return 0;
}