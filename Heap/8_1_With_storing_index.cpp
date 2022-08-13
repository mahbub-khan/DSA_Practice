#include<iostream>
#include<queue>
using namespace std;

void KClosestPointToOrigin(int arr[][2], int row_size, int k){

    priority_queue<pair<int,int>> max_heap;

    for (int i = 0; i < row_size; i++) //we don't need double for loops to traverse both rows and columns as the column size is fixed. We need to traverse the rows only.
    {
        max_heap.push({
            {arr[i][0]*arr[i][0] + arr[i][1]*arr[i][1]}, //first value is the distance
            i //the index(row number actually)
        });

        if (max_heap.size() > k)
        {
            max_heap.pop();
        }
    }

    while (max_heap.size() > 0)
    {
        cout<<arr[max_heap.top().second][0]<<","<<arr[max_heap.top().second][1]<<"  ";
        max_heap.pop();
    }
    
    return;
}

//Driver Code
int main(){

    int arr[4][2] = {{1,3}, {-2,2}, {5,8}, {0,1}};
    int row_size = sizeof(arr) / sizeof(arr[0]); //we only need the row size as the column size is fixed for this particular problem
    int k = 2;  

    KClosestPointToOrigin(arr, row_size, k);

return 0;
}