// color sort

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int z = 0, o = 0, t = 0;

        // Count the number of 0s, 1s, and 2s
        for (int num : nums) {
            if (num == 0) z++;
            else if (num == 1) o++;
            else t++;
        }

        // Fill the array with 0s, 1s, and 2s based on the counts
        int index = 0;
        while (z--) nums[index++] = 0;
        while (o--) nums[index++] = 1;
        while (t--) nums[index++] = 2;
    }
};

