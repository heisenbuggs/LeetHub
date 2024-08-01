class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        int n = details.size();
        for(int i=0; i<n; i++) {
            string s = details[i];
            int a1 = s[11] - '0';
            int a2 = s[12] - '0';
            if(a1*10 + a2 > 60) count++;
        }
        return count;
    }
};