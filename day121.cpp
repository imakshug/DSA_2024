//  Binary Search Tree to Greater Sum Tree

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
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        stack<TreeNode*> alpha;
        TreeNode* node = root;

        while(!alpha.empty() || node != nullptr){
            while(node != nullptr){
                alpha.push(node);
                node = node->right;
            }

            node = alpha.top();
            alpha.pop();
            sum += node->val;
            node->val = sum;

            node = node->left;
        }
        return root;
    }
};
