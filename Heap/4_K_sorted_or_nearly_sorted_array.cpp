#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> KSortedArray(int arr[], int arr_size, int k)
{
    vector<int> v;
    priority_queue<int, vector<int>, greater<int>> min_heap;

    for (int i = 0; i < arr_size; i++)
    {
        min_heap.push(arr[i]);

        if (min_heap.size() > k) //This block will store the values in the vector which are located above size k and then pop it immediately. Ultimately it stores the smallest values as we're using min heap. [smallest values are always at the top in min heap]
        {
            v.push_back(min_heap.top());
            min_heap.pop();
        }
    }

    while (min_heap.size() > 0) //This block will store the values in the vector which are located inside our defined size k and then pop it immediately. Ultimately it stores the largest values as we're using min heap.
    {
        v.push_back(min_heap.top());
        min_heap.pop();
    }
    
return v;
}

//Driver Code
int main()
{
int arr[] = {2, 6, 3, 12, 56, 8};//{2,1,3}; //{6,5,3,2,8,10,9};
int arr_size = sizeof(arr) / sizeof(arr[0]);
int k = 3; 

vector<int> output = KSortedArray(arr, arr_size, k);

for (int i = 0; i < output.size(); i++)
{
    cout<<output.at(i)<<" ";
}

return 0;
}



//Practice problem in gfg: https://practice.geeksforgeeks.org/problems/nearly-sorted-algorithm/0