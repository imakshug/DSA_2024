//951. Flip Equivalent Binary Trees

class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        // Base cases
        if (!root1 && !root2) return true; // Both are null
        if (!root1 || !root2) return false; // One is null
        if (root1->val != root2->val) return false; // Values are different

        // Check both configurations: no flip and with flip
        return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) ||
               (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
    }
};
