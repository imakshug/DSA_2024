// Minimum Deletions to Make String Balanced

class Solution {
public:
    int minimumDeletions(string s) {
        std::vector<int> prefix(s.length());
        int b{}, a{};
        for (int i = 0; i < prefix.size(); i++) {
            prefix[i] = b;
            if (s[i] == 'a') {
                a++;
            }
            else {
                b++;
            }
        }
        for (int i = 0; i < prefix.size(); i++) {
            if (s[i] == 'a')
                a--;
            prefix[i] += a;

        }
        int min{ INT_MAX };
        for (int i = 0; i < prefix.size(); i++) {
                if (prefix[i] < min) min = prefix[i];
            
        }
        //Now prefix is the amount of characters to delete to keep the current character.
        return min;
    }
};
