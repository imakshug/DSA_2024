// count the number of teams

class Solution {
    const int SIZE = 1 << 17;

    struct PointRangeTree {
        vector<int> TREE;
        int n;
        PointRangeTree(int n): n(n), TREE(2 * n){}

        void update(int idx, int val) {
            for (idx += n; idx >= 1; idx >>= 1) {
                TREE[idx] += val;
            }
        }

        int query(int l, int r) {
            int ans = 0;
            for (l += n, r += n; l <= r; l >>= 1, r >>= 1){
                if (l & 1) 
                    ans += TREE[l++];
                if (!(r & 1))
                    ans += TREE[r--];
            }
            return ans;
        }
    };

public:
    int numTeams(vector<int>& rating) {
        PointRangeTree left(SIZE), right(SIZE);

        for (auto x : rating) 
            right.update(x, 1);

        int ans = 0;

        for (auto x : rating) {
            right.update(x, -1);

            int lsmall = left.query(0, x - 1);
            int rsmall = right.query(0, x - 1);
            int lbig = left.query(x + 1, SIZE - 1);
            int rbig = right.query(x + 1, SIZE - 1);

            ans += lsmall * rbig + lbig * rsmall;

            left.update(x, 1);
        }

        return ans;
    }
};
