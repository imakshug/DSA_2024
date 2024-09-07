//1367. Linked List in Binary Tree

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
   // match List

   bool matchList(ListNode* head, TreeNode* root)
   {
     if(head == NULL)
     {
        return true;
     }

     if(root == NULL)
     {
        return false;
     }

     if(root->val != head->val)
     {
        return false;
     }

     bool leftcheck = matchList(head->next , root->left);

     if(leftcheck == true)
     {
        return true;
     }
     bool rightcheck = matchList(head->next , root->right);

     return rightcheck;
   }
    bool isSubPath(ListNode* head, TreeNode* root) {
        // find the head 
        // find is ok or not 
        if(head == NULL)
        {
            return true;
        }

        if(root == NULL)
        {
            return false;
        }

        if(head->val == root->val)
        {
            if(matchList(head , root))
            {
                return true;
            }
        }

        return isSubPath(head , root->left) || isSubPath(head , root->right);

    }
};
