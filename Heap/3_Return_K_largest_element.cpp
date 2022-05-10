#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void KLargestElement(int arr[], int arr_size, int k)
{
    priority_queue<int, vector<int>, greater<int>> min_heap;

    for (int i = 0; i < arr_size; i++)
    {
        min_heap.push(arr[i]);

        if (min_heap.size() > k) //deleting the element if the minheap size is greater than k.
        {
            min_heap.pop();
        }
    }

    cout<<"The "<<k<<" largest elements are: ";

    while (min_heap.size() > 0) //printing all the values(actually k elements) inside the heap. Reducing the size in each step by popping.
    {
        cout<<min_heap.top()<<" ";
        min_heap.pop();
    }
    
return;
}


//Driver Code
int main()
{
int arr[] = {7,10,4,3,20,15};
int arr_size = sizeof(arr) / sizeof(arr[0]);
int k = 2; 

KLargestElement(arr, arr_size, k);

return 0;
}