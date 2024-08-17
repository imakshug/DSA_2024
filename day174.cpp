//1937. Maximum Number of Points with Cost

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();

        vector<long long> prev_row(points[0].begin(), points[0].end());

        for (int i = 1; i < m; ++i) {
            vector<long long> left(n), right(n), curr_row(n);

            left[0] = prev_row[0];
            for (int j = 1; j < n; ++j) {
                left[j] = max(left[j - 1] - 1, prev_row[j]);
            }

            right[n - 1] = prev_row[n - 1];
            for (int j = n - 2; j >= 0; --j) {
                right[j] = max(right[j + 1] - 1, prev_row[j]);
            }

            for (int j = 0; j < n; ++j) {
                curr_row[j] = points[i][j] + max(left[j], right[j]);
            }

            prev_row = curr_row;
        }

        long long maximumpoint = prev_row[0];
        for (int i = 1; i < n; ++i) {
            if (prev_row[i] > maximumpoint) {
                maximumpoint = prev_row[i];
            }
        }

        return maximumpoint;
    }

}
;
