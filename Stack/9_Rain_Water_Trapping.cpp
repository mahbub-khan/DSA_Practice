#include<iostream>
#include<algorithm>
using namespace std;

int TotalRainWaterTrapped(int arr[], int arr_size)
{
int max_left[arr_size], max_right[arr_size];

//finding out the max value of the left side
max_left[0] = arr[0];

for (int i = 1; i < arr_size; i++)
{
    max_left[i] = max(max_left[i-1], arr[i]); 
}

//finding out the max value of the right side
max_right[arr_size-1] = arr[arr_size-1];

for (int i = arr_size-2; i >= 0; i--)
{
    max_right[i] = max(max_right[i+1], arr[i]); 
}


//calculating the amount of water trapped in each position
int water_trapped[arr_size];

for (int i = 0; i < arr_size; i++)
{
    water_trapped[i] = min(max_left[i], max_right[i]) - arr[i];
}


int sum = 0;

for (int i = 0; i < arr_size; i++)
{
    sum = sum + water_trapped[i];
}

return sum;
}



int main()
{
int arr[] = {3,0,0,2,0,4};
int arr_size = sizeof(arr) / sizeof(arr[0]);

int result = TotalRainWaterTrapped(arr, arr_size);
cout<<result<<endl;

return 0;
}