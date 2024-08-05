class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int sum = 0, n = arr.size();
	    for(int i=0; i<n; i++) {
	        sum += arr[i];
	    }

        if(sum%2) return false;
        sum /= 2;
	    vector<vector<int>> dp(n+1, vector<int>(sum+1));
	    
	    for(int i=0; i<=sum; i++) {
	        dp[0][i] = 0;
	    }
	    
	    for(int i=0; i<=n; i++) {
	        dp[i][0] = 1;
	    }
	    
	    for(int i=1; i<=n; i++) {
	        for(int j=1; j<=sum; j++) {
	            if(arr[i-1]<=j) {
	                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
	            }
	            else {
	                dp[i][j] = dp[i-1][j];
	            }
	        }
	    }
        return dp[n][sum];
    }
};