// Reverse Substrings Between Each Pair of Parentheses

class Solution {
public:
    string reverseParentheses(string s) {
        
        string temp = "";

        stack<char>st;

        for(int i = 0;i<s.size();i++){
            temp = "";
            if(s[i] == ')'){
                while(!st.empty() && st.top() != '('){
                    temp.push_back(st.top());
                    st.pop();
                }
                if(!st.empty() && st.top() == '(')
                st.pop();
                for (char ch : temp){
                    st.push(ch);
                }
            }
            else
            st.push(s[i]);
        }
        string ans= "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;

    }
};
