//3152. Special Array II

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums,
                                vector<vector<int>>& queries) {
        const auto n = nums.size();
        auto special_len = std::vector<std::size_t>(n, 1uz);
        for (auto i = 1uz; i < n; i++) {
            if (nums[i - 1] % 2 != nums[i] % 2) {
                special_len[i] = 1 + special_len[i - 1];
            }
        }

        auto result = std::vector<bool>();
        result.reserve(queries.size());
        for (const auto& query : queries) {
            const auto start = query[0];
            const auto end = query[1];
            result.push_back(special_len[end] >= end - start + 1);
        }
        return result;
    }
};
