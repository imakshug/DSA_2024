// Merge Nodes in Between Zeros

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ptr = head;
        ListNode* prev = nullptr;
        while(ptr) {
            int temp = ptr->val;
            if(temp == 0 && !ptr->next) {
                prev->next = nullptr;
                break;
            } else if(temp == 0) {
                if(prev) prev->next = ptr;
                prev = ptr;
            } else {
                prev->val += temp;
            }
            ptr = ptr->next;
        }
        return head;
    }
};
