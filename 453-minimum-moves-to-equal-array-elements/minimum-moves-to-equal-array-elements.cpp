class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0, n = nums.size(), mini = INT_MAX;
        for(int i=0; i<n; i++) {
            sum += nums[i];
            mini = min(mini, nums[i]);
        }
        return sum - mini * n;
    }
};