//567. Permutation in String

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //int len1 = s1.size(), len2 = s2.size();
        if(s1.size() > s2.size()) return false;
        vector<int> s1c(26, 0), ws(26, 0);
        for(int i = 0; i<s1.size(); i++){
            s1c[s1[i] - 'a']++;
            ws[s2[i] - 'a']++;
        } 
        if(s1c == ws) return true;
        for(int i = s1.size(); i<s2.size(); i++){
            ws[s2[i] - 'a']++;
            ws[s2[i - s1.size()] - 'a']--;
            if(s1c == ws) return true;
        }
        return false;
    }
};
