#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

vector<int> NSL(int arr[],int arr_size)
{
    vector<int> v;
    stack<int> s;

    for (int i = 0; i < arr_size; i++)
    {
        if (s.size() == 0)  //if the stack is empty
        {
            v.push_back(-1);
        }
        else if(s.size() > 0 && s.top() < arr[i])
        {
            v.push_back(s.top());
        }
        else if(s.size() > 0 && s.top() >= arr[i])
        {
            while (s.size() > 0 && s.top() >= arr[i])
            {
                s.pop();
            }

            //if the one of the conditions in the while loop is false the below portion will take care of it
            if (s.size() == 0)
            {
                v.push_back(-1);
            }
            else if(s.top() < arr[i])
            {
                v.push_back(s.top());
            }
            
        }

        s.push(arr[i]); //While the checking is complete pushing the array value in the stack for further checking
    }
    
    return v;
}


int main()
{
int arr[] = {6, 2, 5, 4, 5, 1, 6};
int arr_size = sizeof(arr) / sizeof(arr[0]);

vector<int> output = NSL(arr, arr_size);

//printing the values from the vector
for (int i = 0; i < output.size(); i++)
{
    cout<<output.at(i)<<" ";
}

return 0;
}