// 2981. Find Longest Special Substring That Occurs Thrice I

class Solution {
public:
    void update(int a[], int len) {
        if (len > a[0]) {
            a[2] = a[1];
            a[1] = a[0];
            a[0] = len;
        } else if (len > a[1]) {
            a[2] = a[1];
            a[1] = len;
        } else if (len > a[2]) {
            a[2] = len;
        }
    }
    int maximumLength(string s) {
        int freq[26][3] = {0};
        int len = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] != s[i - 1]) {
                update(freq[s[i - 1] - 'a'], len);
                len = 1;
            } else {
                len++;
            }
            if (i == ~-s.size()) {
                update(freq[s[i] - 'a'], len);
            }
        }
        int best = 0;
        for (const int* a : freq) {
            best = std::max({best, a[0] - 2, std::min({a[0] - 1, a[1]}), a[2]});
        }
        return best > 0 ? best : -1;
    }
};
