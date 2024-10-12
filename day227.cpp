//921. Minimum Add to Make Parentheses Valid

class Solution {
public:
    int minAddToMakeValid(string s) {
        vector<char> v;
        int  left =0;
        for(int i=0; i<s.size() ;i++){
            if(s[i] == '(') v.push_back(')');
            else {
                if(v.empty()) left++;
                else v.pop_back();
            }
        }
        return v.size()+left;
        
    }
};
