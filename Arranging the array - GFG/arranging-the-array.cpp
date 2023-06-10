//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends
class Solution {
public:
    void Rearrange(int arr[], int n) {
        //fill_n(arr, n, 0);
        int k = 0;
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(arr[i] < 0) {
                swap(arr[i], arr[k++]);
            }
            else 
                q.push(arr[i]);
        }
        while(k < n) {
            arr[k++] = q.front();
            q.pop();
        }
        // for(int i = 0; i < n; i++)
        //     arr[i] = 1;
        // Your code goes here
        // int k = -1;
        // for (int i = 0; i < n; i++) {
        //     if(arr[i] < 0) {
        //         k++;
        //         swap(arr[k], arr[i]);
        //     }
        //     else
        //         continue;
        // }
    }
};

//{ Driver Code Starts.
void Rearrange(int arr[], int n);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        long long j=0;
        Solution ob;
        ob.Rearrange(arr, n);
      
        for (int i = 0; i < n; i++) 
            cout << arr[i] << " "; 
        cout << endl;  
    }
    return 0; 
} 
// } Driver Code Ends