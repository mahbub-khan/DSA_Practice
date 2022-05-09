#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

vector<int> NSR_index(int arr[], int arr_size)
{
    vector<int> v_right;
    stack<pair<int, int>> s;
    int pseudo_index = arr_size;

    for (int i = arr_size - 1; i >= 0; i--)
    {
       if (s.size() == 0)
       {
           v_right.push_back(pseudo_index);
       }
       else if (s.size() > 0 && s.top().first < arr[i])
       {
           v_right.push_back(s.top().second);
       }
       else if (s.size() > 0 && s.top().first >= arr[i])
       {
           while (s.size() > 0 && s.top().first >= arr[i])
           {
               s.pop();
           }

           if (s.size() == 0)
           {
               v_right.push_back(pseudo_index);
           }
           else if (s.top().first < arr[i])
           {
               v_right.push_back(s.top().second);
           } 
       }
       s.push({arr[i], i});
    }
    reverse(v_right.begin(), v_right.end());
    return v_right;
}

vector<int> NSL_index(int arr[], int arr_size)
{
    vector<int> v_left;
    stack<pair<int, int>> s;
    int pseudo_index = -1;

    for (int i = 0; i < arr_size; i++)
    {
       if (s.size() == 0)
       {
           v_left.push_back(pseudo_index);
       }
       else if (s.size() > 0 && s.top().first < arr[i])
       {
           v_left.push_back(s.top().second);
       }
       else if (s.size() > 0 && s.top().first >= arr[i])
       {
           while (s.size() > 0 && s.top().first >= arr[i])
           {
               s.pop();
           }

           if (s.size() == 0)
           {
               v_left.push_back(pseudo_index);
           }
           else if (s.top().first < arr[i])
           {
               v_left.push_back(s.top().second);
           } 
       }
       s.push({arr[i], i});
    }
    return v_left;
}

int MaxAreaHistogram(int arr[], int arr_size)
{
    vector<int> left = NSL_index(arr, arr_size);
    vector<int> right = NSR_index(arr, arr_size);
    int width[arr_size], area[arr_size];
    int result;

    for (int i = 0; i < arr_size; i++) //finding out how long a value can be expanded without interruption
    {
        width[i] = right[i] - left[i] - 1;
    }

    for (int i = 0; i < arr_size; i++)
    {
        area[i] = arr[i]*width[i];
    }

    result = *max_element(area, area+arr_size);    
    return result;
}

//Driver Code
int main()
{
int arr[] = {6, 2, 5, 4, 5, 1, 6};
int arr_size = sizeof(arr) / sizeof(arr[0]);

int output = MaxAreaHistogram(arr, arr_size);
cout<<output;

// vector<int> output_right = NSR_index(arr, arr_size);

// //printing the values from the vector
// for (int i = 0; i < output_right.size(); i++)
// {
//     cout<<output_right.at(i)<<" ";
// }
// cout<<"Left: "<<endl;
// vector<int> output_left = NSL_index(arr, arr_size);

// //printing the values from the vector
// for (int i = 0; i < output_left.size(); i++)
// {
//     cout<<output_left.at(i)<<" ";
// }


return 0;
}