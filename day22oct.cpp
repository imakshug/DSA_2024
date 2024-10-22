//2583. Kth Largest Sum in a Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (!root) return -1;

        queue<TreeNode*> q;
        q.push(root);

        vector<long long> levelSums;
        
        while (!q.empty()) {
            int levelSize = q.size(); 
            long long currentLevelSum = 0;
            
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                
                currentLevelSum += node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            levelSums.push_back(currentLevelSum);
        }
        
        if (levelSums.size() < k) return -1;
        
        sort(levelSums.rbegin(), levelSums.rend());

        return levelSums[k - 1];
        
    }
};
