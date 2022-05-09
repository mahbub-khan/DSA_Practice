#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> NGL_Stock(int arr[], int arr_size)
{
    vector<int> v;
    stack<pair<int, int>> s; //declaring a pair stack to store the nearest greater to left value and it's index

    for (int i = 0; i < arr_size; i++)
    {
        //if the stack is empty
        if (s.size() == 0)
        {
            v.push_back(-1);
        }
        else if (s.size() > 0 && s.top().first > arr[i]) //comparing the stack value with arr[i]
        {
            v.push_back(s.top().second); //inserting the index into the vector
        }
        else if (s.size() > 0 && s.top().first <= arr[i])
        {
            while (s.size() > 0 && s.top().first <= arr[i])
            {
                s.pop();
            }

            if (s.size() == 0)
            {
                v.push_back(-1);
            }
            else if (s.top().first > arr[i])
            {
                v.push_back(s.top().second);
            }
        }
        
        s.push({arr[i], i}); //While the checking is complete inserting both the value and it's index for further checking
    }

    //Here is the catch
    for (int j = 0; j < v.size(); j++)
    {
        v[j] = j - v[j]; //substracting the index stored in the vector from the array index to get the final result 
    }
    
    return v;
}

//Driver Code
int main()
{
int arr[] = {100, 80, 60, 70, 60, 75, 85};
int arr_size = sizeof(arr) / sizeof(arr[0]);

vector<int> output = NGL_Stock(arr, arr_size);

//printing the values from the vector 
for (int i = 0; i < output.size(); i++)
{
    cout<<output.at(i)<<" ";
}

return 0;
}