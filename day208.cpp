// You are given a string s. You can convert s to a 
// palindrome by adding characters in front of it.

// Return the shortest palindrome you can find by performing this transformation.


// Observation:
//     - 0 <= s.length <= 5 * 104
//     - s consists of lowercase English letters only.
//     - damn that hard for me \U0001fae1\U0001f979

// How to solve:
//     - Use editorial.
//     - Two pointer
//     - KMP algo -> using this
//     - Hashing
//     - Manacher's Algorithm'

class Solution {
private:
    //Helper function to create LPS
    vector<int> buildLPS(const string& s){
        vector<int> array_(s.length(), 0);

        int length = 0;
        
        for(int i = 1; i < s.length(); i++){
            
            while(length > 0 && s[i] != s[length]){
                length = array_[length - 1];
            }

            if (s[i] == s[length]) {
                length++;
            }

            array_[i] = length;
        }

        return array_;
    }
public:
    string shortestPalindrome(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        if(s.length() == 0){
            return s;
        }

        string reverseString = string(s.rbegin(), s.rend());
        
        string combineString = s + "#" + reverseString;
        vector<int> LPS = buildLPS(combineString);

        int palindrome = LPS[combineString.length() - 1];

        string suffer = reverseString.substr(0, s.length() - palindrome);

        return suffer + s;
    }
};
