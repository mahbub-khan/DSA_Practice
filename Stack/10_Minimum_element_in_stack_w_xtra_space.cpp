#include<bits/stdc++.h>
#include<stack>
using namespace std;

stack<int> s;
stack<int> ss;

int getMin()
{
    if (ss.size() == 0)
        return -1;

    return ss.top();
}

void pushElement(int a)
{
    s.push(a);

    if (ss.size()==0 || a <= ss.top())
        ss.push(a);
    
    return; 
}

int popElement()
{
    if (s.size() == 0)
    {
        return -1;
    }

    int ans = s.top();
    s.pop(); //Keep an eye here. We should put this after declaring the ans

    if (ans == ss.top())
    {
        ss.pop();
    }
    return ans;

}

int main()
{
int a = 18;
pushElement(a);
int b = 19; 
pushElement(b);
int c = 10; 
pushElement(c);
popElement();popElement();popElement();

cout<<getMin(); 

return 0;
}