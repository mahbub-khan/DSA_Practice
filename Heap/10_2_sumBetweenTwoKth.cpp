#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int sumBetweenTwoKth(int arr[], int size, int k1, int k2){

    priority_queue<int> max_heap;

    for (int i = 0; i < size; i++)
    {
        max_heap.push(arr[i]);

        if (max_heap.size() > max(k1,k2) - 1) //to create a maxheap of size klarger - 1(as we exclude the value at klarge position)
        {
            max_heap.pop();
        } 
    }

    int sum = 0;

    for (int i = 0; i < abs(k1-k2) - 1; i++) //to add all the elements until ksmaller -1 (as we exclude the value at ksmall position)
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
    int k1 = 3, k2 = 6;

    int output = sumBetweenTwoKth(arr,size,k1,k2);
    cout<<output;

    return 0;
}
