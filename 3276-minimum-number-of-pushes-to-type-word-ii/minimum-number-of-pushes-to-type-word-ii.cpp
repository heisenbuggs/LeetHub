class Solution {
public:
    bool static comp(pair<char, int> a, pair<char, int> b) {
        return a.second > b.second;
    }

    int minimumPushes(string word) {
        int n = word.length(), sum=0;
        unordered_map<int, int> mp;
        for(int i=0; i<word.length(); i++) {
            mp[word[i]]++;
        }
        vector<pair<char, int>> v;
        for(auto x: mp) {
            v.push_back({x.first, x.second});
        }
        sort(v.begin(), v.end(), comp);
        for(int i=0; i<v.size(); i++) cout << v[i].first << " " << v[i].second << "\n";
        for(int i=0; i<26; i++) {
            if(i>=v.size()) break;
            sum += (v[i].second * (i/8 + 1));
        }
        return sum;
    }
};