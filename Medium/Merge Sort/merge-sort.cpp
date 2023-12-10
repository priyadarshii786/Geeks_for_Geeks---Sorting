//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    /*
    
Time Complexity : O(n * log n)

Space Complexity : O(n)

1. Divide the Array into two subarrays at the middle recursively.

2. Merge the two subarrays at each step. Since the two subarrays are sorted it takes O(n) time to merge array as sorted.

3. Store the values of the two subarrays in two temp arrays so that you can directly update the new values into the original array.

4. Maintain two pointers each at the start of the two subarrays and pointer at the start of the left subarray.

5. Take the minimum of the two values of the iterators in two subarrays and write it to the original array.

6. If there are any elements in the left array add it to the original array and then if there are any elements in the right array add it to the original array. (You can do it in any order because only one of those arrays will have elements yet to be added)

Time Complexity Analysis:

    T(n) = T(n/2) + T(n/2) + Complexity of Merge

Since left and right are sorted in their previous steps, it's complexity is O(n)

    T(n) = 2 * T(n/2) + O(n)

    T(n) = 2 * (2 * T(n/4) + n/2) + O(n)

    T(n) = 4 * T(n/4) + 2 * O(n)

    T(n) = 2^k * T(n/2^k) + k * O(n)

    At n = 2^k => k = log n to the base 2

    T(n) = n * T(n/n) + log n * O(n)

    T(n) = n + O ( n * log n)

    T(n) = O(n * logn)
    
    */
    public:
    void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         // jai ganesh
         
         
    int left = m - l + 1, right = r - m;
    int leftArr[left], rightArr[right];
    
    for(int i=0;i<left;i++)
    leftArr[i] = arr[l + i];
    
    for(int i=0;i<right;i++)
    rightArr[i] = arr[m+1+i];
    
    int i = 0, j = 0, k = l;
    while(i < left && j < right)
    {
        if(leftArr[i] < rightArr[j])
        arr[k++] = leftArr[i++];
        
        else
        arr[k++] = rightArr[j++];
    }
    while(i < left)
    arr[k++] = leftArr[i++];
    
    while(j < right)
    arr[k++] = rightArr[j++];
        
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l < r)
        {
           int mid = l + (r - l)/2;
           mergeSort(arr, l, mid);
           mergeSort(arr, mid+1, r);
           merge(arr, l, mid, r);
        }
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends