// 1545. Find Kth Bit in Nth Binary String

class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1) return '0';

        if (k == (1<<(n - 1))) return '1';
        else if (k < (1<<(n - 1)))  
        {
            return findKthBit(n - 1, k);
        }
        char res = findKthBit(n - 1, (1<<n) - k);
        if (res == '0') return '1';
        return '0';
    }
};
