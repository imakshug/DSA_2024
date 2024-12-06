//2554. Maximum Number of Integers to Choose From a Range I

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int current_sum = ((1 + n) * n) / 2, count = n;
        vector<bool> processed(n + 1, false);
        for (auto banned_number: banned) {
            if (banned_number <= n && !processed[banned_number]) {
                current_sum -= banned_number;
                count--;
                processed[banned_number] = true;
            }
        }

        for (int i = n; i >= 1; i--) {
            if (current_sum <= maxSum) {
                break;
            } else if (processed[i]) {
                continue;
            } else {
                current_sum -= i;
                count--;
            }
        }

        return count;
    }
};
