//2220. Minimum Bit Flips to Convert Number

class Solution {
public:
    int minBitFlips(int start, int goal) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        return __builtin_popcount(start ^ goal);
    }
};
