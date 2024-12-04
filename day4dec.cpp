//2825. Make String a Subsequence Using Cyclic Increments


class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0, j = 0;
        while (i < str1.size() && j < str2.size()) {
            if (str1[i] == str2[j] || (char)((str1[i] - 'a' + 1) % 26 + 'a') == str2[j]) {
                i++;
                j++;
            } else {
                i++;
            }
        }
        return j == str2.size();
    }
};
