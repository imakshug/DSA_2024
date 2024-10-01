//1497. Check If Array Pairs Are Divisible by k

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> remainderFreq;
        
        for (int num : arr) {
            int remainder = num % k;
            if (remainder < 0) remainder += k;
            remainderFreq[remainder]++;
        }
        
        for (auto& [remainder, freq] : remainderFreq) {
            if (remainder == 0 || 2 * remainder == k) {
                if (freq % 2 != 0) return false;
            } else {
                int otherFreq = remainderFreq[k - remainder];
                if (freq != otherFreq) return false;
            }
        }
        
        return true;
    }
};
