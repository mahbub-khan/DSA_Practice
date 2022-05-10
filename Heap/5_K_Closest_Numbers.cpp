#include<iostream>
#include<queue>
using namespace std;

void KClosestNumbers(int arr[], int arr_size, int k, int x)
{
    priority_queue<pair<int, int>> max_heap;

    for (int i = 0; i < arr_size; i++)
    {
        max_heap.push({abs(arr[i] - x), arr[i]});

        if (max_heap.size() > k)
        {
            max_heap.pop();
        }
    }

    while (max_heap.size() > 0)
    {
        cout<<max_heap.top().second<<" ";
        max_heap.pop();
    }
    
    return;
}

//Driver Code
int main()
{
int arr[] = {9,5,7,8,10};
int arr_size = sizeof(arr) / sizeof(arr[0]);
int k = 3, x = 7;

KClosestNumbers(arr, arr_size, k, x);

return 0;
}