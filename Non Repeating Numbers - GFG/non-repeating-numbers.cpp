//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) {
        int temp=0;
        
        for(auto it : nums) 
            temp ^= it;
        int firstSet=0;
        while(temp) {
            if(temp & 1)
                break;
            temp = temp >> 1;
            firstSet++;
        }
 
        // as temp is XOR of all, which is XOR of (ans1^ans2) as rest of them occure twice and became zero
        // (1^1=0) and (1^0=1) 
        // if ith bit is set in the XOR of both which means ith bit of one is 1 and 0 of another
        // with this we can divide numbers in groups i.e ith bit set and unset
        // now we can just xor both groups separately
        int set = 0, unset = 0;
        for(auto it : nums) {
            if(it >> firstSet & 1)
                set ^= it;
            else
                unset ^= it;
        }
        return {min(set, unset), max(set, unset)};
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends