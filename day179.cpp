// number compliment

class Solution {
public:
    int findComplement(int num) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int m = num;
        int mask = 0;
        if (num == 0) {
            return 1;
        }
        while (m != 0) {
            mask = (mask << 1) | 1;
            m = m >> 1;
        }
        int ans = (~num) & mask;
        return ans;
    }
};

