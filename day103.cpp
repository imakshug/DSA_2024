// 846. Hand of Straights

#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        // If the total number of cards isn't a multiple of groupSize, return false
        if (n % groupSize != 0) {
            return false;
        }

        // Use a map to count occurrences of each card
        unordered_map<int, int> mp;
        for (int card : hand) {
            mp[card]++;
        }

        // Sort the hand to process the smallest card first
        sort(hand.begin(), hand.end());

        for (int card : hand) {
            if (mp[card] > 0) {
                // Try to form a group starting with the current card
                for (int i = 0; i < groupSize; ++i) {
                    if (mp[card + i] > 0) {
                        mp[card + i]--;
                    } else {
                        // If any card needed to form a group is missing, return false
                        return false;
                    }
                }
            }
        }

        return true;
    }
};
