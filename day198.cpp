//2807. Insert Greatest Common Divisors in Linked List

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
class Solution {
private:
    int getGCD(int n, int m){
        if(n == 0 || m == 0) return n + m;
        return getGCD(abs(n-m), min(n, m));
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* start = head;
        ListNode* end = head->next;
        if(end == NULL) return start;
        while(end != NULL){
            ListNode* add = new ListNode(getGCD(start->val, end->val));
            start->next = add;
            add->next = end;
            start = end;
            end = end->next;
        }

        return head;
    }
};
