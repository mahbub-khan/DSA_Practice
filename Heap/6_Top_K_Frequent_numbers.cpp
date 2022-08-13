#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;

void TopKFrequentNums(int arr[], int arr_size, int k)
{
    unordered_map<int,int> mp;

    for (int i = 0; i < arr_size; i++) //finding out the frequency of values using unordered map
    {
        mp[arr[i]]++; //mp[arr[i]] + = 1; tTo understand this line please look at the lecture notes or https://www.geeksforgeeks.org/unordered_map-in-cpp-stl/  or https://www.youtube.com/watch?v=92lNq_zLKd8&ab_channel=Let%27sCodeIt... or https://www.youtube.com/watch?v=Uv0kd7mM0ts&ab_channel=HelloWorld
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> min_heap; //creating a min heap pair

    for (auto i = mp.begin(); i != mp.end(); i++) //inserting the values in heap from the unordered_map mp
    {
        min_heap.push({i -> second, i -> first}); //inserting the frequency first as it is the key here

        if (min_heap.size() > k)
        {
            min_heap.pop();
        }
    }

    while (min_heap.size() > 0) //printing out the values from the heap
    {
        cout<<min_heap.top().second<<" ";
        min_heap.pop();
    }

    return;
}



//Driver Code
int main()
{
int arr[] = {1,1,1,3,2,2,4};
int arr_size = sizeof(arr) / sizeof(arr[0]);
int k = 2;

TopKFrequentNums(arr, arr_size, k);


return 0;
}