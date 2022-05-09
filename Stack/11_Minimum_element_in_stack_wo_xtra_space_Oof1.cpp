#include<bits/stdc++.h>
#include<stack>
using namespace std;

stack<int> s;
int minElement;

int getMin()
{
    if (s.size() == 0)
        return -1;
    return minElement;
}

void push(int a)
{
    if (s.size() == 0)
    {
        s.push(a);
        minElement = a;
    }
    else
    {
        if (a >= minElement)
        {
            s.push(a);
        }
        else if(a < minElement)
        {
            s.push(2*a - minElement);
            minElement = a;
        }
        
    }
   return; 
}

void pop()
{
    if (s.size() == 0)
    {
        return;
    }
    else
    {
        if (s.top() >= minElement)
        {
            s.pop();
        }
        else if(s.top() < minElement)
        {
            minElement = 2*minElement - s.top();
            s.pop();
        }
    }
}

// int top()
// {
//     if (s.size() == 0)
//     {
//         return -1;
//     }
//     else
//     {

//      if (s.top() >= minElement)
//      {
//         return s.top();
//      }
//      else if (s.top() < minElement)
//      {
//         return minElement;
//      }

//     } 

// }



//To avoid the warning
int top()
{
    int ans;
    if (s.size() == 0)
    {
        ans = -1;
    }
    else
    {

     if (s.top() >= minElement)
     {
        
        ans = s.top();
     }
     else if (s.top() < minElement)
     {
        ans = minElement;
     }

    } 
    return ans;
}




int main()
{
int a = -5; push(a);
int b = -7; push(b);
int c = -3; push(c);


cout<<getMin();

return 0;
}