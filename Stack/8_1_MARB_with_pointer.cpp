#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

// const int row = 4;
// const int col = 5;

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




int MaxAreaBinaryMatrix(int *arr, int row, int col)
{
    int arr_bin[col];
    
    for (int j = 0; j < col; j++) //taking input of the first row 
    {
        arr_bin[j] = *(arr+0+j);
    }
    
    int max_value = MaxAreaHistogram(arr_bin,col); //returning the MAH of row 1
    
    for (int i = 1; i < row; i++) //taking input of the 2nd row to last row
    {
        for (int j = 0; j < col; j++)
        {
            if (*(arr+i*col+j) == 0)
            {
                arr_bin[j] = 0;
            }
            else
            {
                arr_bin[j] = arr_bin[j] + *(arr+i*col+j);
            } 
        }
        max_value = max(max_value, MaxAreaHistogram(arr_bin,col)); //finding out the max value after iterating each row
    }

    return max_value;
}

int main()
{
int arr[4][4] = {{0,1,1,0}, {1,1,1,1}, {1,1,1,1}, {1,1,0,0}};
// int arr[4][5] ={ { 0, 1, 0, 1, 1 },
//                 { 1, 1, 0, 0, 1 },
//                 { 1, 1, 0, 1, 1 },
//                 { 1, 1, 1, 1, 1 }};
int row = sizeof(arr) / sizeof(arr[0]); //finding the row size
int col = sizeof(arr[0]) / sizeof(int); //finding the column size

int result = MaxAreaBinaryMatrix((int *)arr,row,col);

cout<<result;


return 0;
}