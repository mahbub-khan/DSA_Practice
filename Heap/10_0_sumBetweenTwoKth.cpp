#include<iostream>
#include<queue>
using namespace std;

int KthSmallest(int arr[], int size, int k){

    priority_queue<int> max_heap;

    for (int i = 0; i < size; i++)
    {
        max_heap.push(arr[i]);

        if (max_heap.size() > k)
        {
            max_heap.pop();
        } 
    }
    
    return max_heap.top();
}

//Driver Code
int main(){

    int arr[] = {1,3,5,11,12,15};
    int size = sizeof(arr)/sizeof(arr[0]);
    int k1 = 3, k2 = 6;

    int first = KthSmallest(arr,size,k1);
    int second = KthSmallest(arr,size,k2);

    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > first & arr[i] < second)
        {
            sum += arr[i];
        }
        
    }
    
    cout<< sum;

    return 0;
}
