#include<iostream>
#include<queue>
using namespace std;

int MinimizeCost(int arr[], int size){
    priority_queue<int, vector<int>, greater<int>> min_heap;

    for (int i = 0; i < size; i++)
    {
        min_heap.push(arr[i]);
    }
    
    int cost = 0;

    while (min_heap.size() >= 2)
    {
        int first = min_heap.top();
        min_heap.pop();
        int second = min_heap.top();
        min_heap.pop();

        cost = cost + first + second; 
        min_heap.push(first+second); //pushing the new cost to heap after merging the 2 lowest cost ropes
    }
    
    return cost;
}

//Driver Code
int main(){
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);

    int output = MinimizeCost(arr, size);
    cout<<output;
    
    return 0;
}
