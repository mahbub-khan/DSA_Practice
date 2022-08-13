#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;

void TopKFrequentNums(int arr[], int arr_size)
{
    unordered_map<int,int> mp;

    for (int i = 0; i < arr_size; i++) //finding out the frequency of values using unordered map
    {
        mp[arr[i]]++;
    }

    priority_queue<pair<int,int>> max_heap;

    for (auto i = mp.begin(); i != mp.end(); i++) //inserting the values in heap from the unordered_map mp
    {
        max_heap.push({i -> second, i -> first});
    }

    while (max_heap.size() > 0)
    {
        int frequency = max_heap.top().first;
        int element = max_heap.top().second;

        for (int i = 0; i < frequency; i++)
        {
            cout<<element<<" ";
        }
        max_heap.pop();

    }

    return;
}



//Driver Code
int main()
{
int arr[] = {1,2,1,3,1,2,4};
int arr_size = sizeof(arr) / sizeof(arr[0]);


TopKFrequentNums(arr, arr_size);


return 0;
}