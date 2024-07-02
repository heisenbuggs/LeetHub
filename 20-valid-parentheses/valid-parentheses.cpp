class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0; i<s.length(); i++) {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') {
                st.push(s[i]);
            }
            else {
                if(st.empty()) return false;
                else if(!isEqual(st.top(), s[i])) return false;
                else st.pop();
            }
        }
        return st.empty()==true;
    }

    bool isEqual(char top, char curr) {
        return (top=='{' && curr=='}') ||
        (top=='[' && curr==']') || (top=='(' && curr==')');
    }
};