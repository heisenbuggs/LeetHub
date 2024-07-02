class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int> mp;
        stack<int> st;
        int x;
        st.push(nums2[nums2.size()-1]);
        mp[nums2[nums2.size()-1]] = -1;
        for(int i=nums2.size()-2; i>=0; i--) {
            while(!st.empty() && st.top()<=nums2[i]) {
                st.pop();
            }
            x = st.empty() ? -1 : st.top();
            mp[nums2[i]] = x;
            st.push(nums2[i]);
        }

        for(int i=0; i<nums1.size(); i++) {
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};