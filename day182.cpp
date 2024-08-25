//145. Binary Tree Postorder Traversal

class Solution {
public:
    Solution() {
       ios_base::sync_with_stdio(false);
       cin.tie(nullptr);
       cout.tie(nullptr);
    }

    vector<int> ret;

    void print(TreeNode *root) {
       if (root == NULL)
          return;
       print(root->left);
       print(root->right);
       ret.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode *root) {
       print(root);
       return ret;
    }
};
