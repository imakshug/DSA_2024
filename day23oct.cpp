//2641. Cousins in Binary Tree II

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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        queue<TreeNode*> newq;
        TreeNode* newRoot = new TreeNode(0);
        newq.push(newRoot);
        while(!q.empty())
        {
            int numNode = q.size();
            int curSum = 0; 
            for (int i = 0; i < numNode; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if (node->left)
                {
                    curSum += node->left->val;
                }
                if (node->right)
                {
                    curSum += node->right->val;
                }
                q.push(node);
            }

            for (int i = 0; i < numNode; i++)
            {
                TreeNode* node = q.front();
                q.pop();

                TreeNode* newNode = newq.front();
                newq.pop();
                
                int temp = 0;
                if (node->left)
                {
                    temp += node->left->val;
                }
                if (node->right)
                {
                    temp += node->right->val;
                }

                if (node->left)
                {
                    newNode->left = new TreeNode(curSum - temp);
                    q.push(node->left);
                    newq.push(newNode->left);
                }
                if (node->right)
                {
                    newNode->right = new TreeNode(curSum - temp);
                    q.push(node->right);
                    newq.push(newNode->right);
                }
            }
        }
        return newRoot;
    }
};
