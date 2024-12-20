// 2415. Reverse Odd Levels of Binary Tree

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
    vector<TreeNode*>v;
    void bfs(TreeNode* root)
    {
        if(!root)return;
        queue<TreeNode*>q;
        q.push(root);
        int lvl=0;
        while(!q.empty())
        {
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                TreeNode* f=q.front();
                q.pop();
                if(f->left)
                {
                    q.push(f->left);
                    v.push_back(f->left);
                }
                if(f->right)
                {
                    q.push(f->right);
                    v.push_back(f->right);
                }
            }
            if(lvl%2==0)
            {
                for(int i=0,j=v.size()-1;i<v.size()/2;i++,j--)
                {
                    swap(v[j]->val,v[i]->val);
                }
            }
            v.clear();
            lvl++;
        }
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        bfs(root);
        return root;
    }
};
