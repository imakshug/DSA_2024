// no. of good leaf node pair 

class Solution {
public:
    int ans = 0;
    vector<int> helper(TreeNode* root, int dis){
        if (root == NULL) return {};
        if(root->left == NULL && root->right == NULL) return {1};
        vector<int> Left = helper(root->left, dis);
        vector<int> Right = helper(root->right, dis);
        cout<<root->val<<" ";
        for(int i=0; i<Left.size(); i++){
            for(auto j:Right){
                ans += Left[i] + j <= dis ? 1: 0;
            }
            Left[i]++;
        } 
        for(auto i:Right){
            Left.push_back(1+i);
        }
        return Left;
    }
    int countPairs(TreeNode* root, int distance) {
        vector<int> Left, Right;
        helper(root, distance);
        return ans;
    }
};
