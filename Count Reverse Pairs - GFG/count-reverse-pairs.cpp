//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void findAns(vector<int> &arr, int low, int mid, int high, int &ans)
    {
        int right=mid+1;
        for(int i=low; i<=mid; i++)
        {
            while(right<=high && arr[i]>2*arr[right])
            {
                right++;
                
            }
            ans=ans+(right-(mid+1));
            
        }
    }
    void merge(vector<int> &arr, int low, int mid, int high)
    {
        int left = low;
        vector<int> v;
        int right = mid + 1;
        while (left <= mid && right <= high)
        {
            if (arr[left] < arr[right])
            {
                v.push_back(arr[left]);
                left++;
            }
            else
            {
                v.push_back(arr[right]);
                right++;
            }
        }
        while (left <= mid)
        {
            v.push_back(arr[left]);
            left++;
        }
        while (right <= high)
        {
            v.push_back(arr[right]);
            right++;
        }
        int x = 0;
        while (low <= high)
        {
            arr[low++] = v[x++];
        }
    }
    void mergeSort(vector<int> &arr, int low, int high, int &ans)
    {
        int mid = (low + high) / 2;
        if (low == high)
        {
            return;
        }
        mergeSort(arr, low, mid, ans);
        mergeSort(arr, mid + 1, high, ans);
        findAns(arr, low, mid, high, ans);
        merge(arr, low, mid, high);
    }
    int countRevPairs(int n, vector<int> arr)
    {
        int low = 0;
        int high = n - 1;
        int ans = 0;
        mergeSort(arr, low, high, ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countRevPairs(n, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends