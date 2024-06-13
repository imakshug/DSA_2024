//  Minimum Number of Moves to Seat Everyone


#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int minMovesToSeat(std::vector<int>& seats, std::vector<int>& students) {
        // Find the maximum element in both seats and students to determine the upper bound
        int upper = std::max(*std::max_element(seats.begin(), seats.end()), *std::max_element(students.begin(), students.end()));
        // Create a vector to count the differences at each position
        std::vector<int> cnt(upper + 1, 0);
        int ans = 0, cur = 0;
        // Update the counts for seats and students
        for (int i = 0; i < seats.size(); ++i) {
            cnt[seats[i]]--;
            cnt[students[i]]++;
        }
        // Calculate the minimum moves required
        for (int i = 0; i <= upper; ++i) {
            cur += cnt[i];
            ans += std::abs(cur);
        }
        return ans;
    }
};

