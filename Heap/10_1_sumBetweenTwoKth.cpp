#include<iostream>
#include<queue>
using namespace std;

int sumBetweenTwoKth(int arr[], int size, int ksmall, int klarge){

    priority_queue<int> max_heap;

    for (int i = 0; i < size; i++)
    {
        max_heap.push(arr[i]);

        if (max_heap.size() > klarge - 1) //to create a maxheap of size klarger - 1 (as we exclude the value at klarge position)
        {
            max_heap.pop();
        } 
    }

    int sum = 0;

    while (max_heap.size() > ksmall) //to add all the elements until ksmaller -1 (as we exclude the value at ksmall position)
    {
        sum += max_heap.top();
        max_heap.pop();
    }
    
    return sum;
}

//Driver Code
int main(){

    int arr[] = {1,3,5,11,12,15};
    int size = sizeof(arr)/sizeof(arr[0]);
    int ksmall = 2, klarge = 6;

    int output = sumBetweenTwoKth(arr,size,ksmall,klarge);
    cout<<output;

    return 0;
}
