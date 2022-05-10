#include<iostream>
#include<queue>
using namespace std;


int KthSmallest(int arr[], int arr_size, int k)
{
    priority_queue<int> max_heap;

    for (int i = 0; i < arr_size; i++)
    {
        max_heap.push(arr[i]);

        if (max_heap.size() > k)  //deleting the element if the maxheap size is greater than k.
        {
            max_heap.pop();
        }
    }

    return max_heap.top();
}


//Driver Code
int main()
{
int arr[] = {7,10,4,3,20,15};
int arr_size = sizeof(arr) / sizeof(arr[0]);
int k = 2; 

int result = KthSmallest(arr, arr_size, k);

cout<<"The Kth Smallest element is: "<<result<<endl;

return 0;
}