//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int countTriplet(int arr[], int n)
	{
	    // Your code goes here
	    // jai ganesh
	    int i=n-1;
        int count=0;
        sort(arr,arr+n);
        while(i>=2)
        {
            int l=0;
            int h=i-1;
            while(l<h)
            {
                int sum=arr[l]+arr[h];
                if(sum==arr[i])
                {
                    count++;
                    l++;
                    h--;
                }
                else if(sum>arr[i])
                h--;
                
                else
                l++;
            }
            
            i--;
        }
        return count;
	}
};

//{ Driver Code Starts.


int main() 
{
   	
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

        Solution ob;
        cout << ob.countTriplet(arr, n) << "\n";

    }

    return 0;
}
// } Driver Code Ends