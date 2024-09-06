// delete nodes from linked list presennt in the array

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
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> set={};
        for( int num : nums){
            set.insert(num);
        }
        while(head != nullptr && set.find(head->val)!=set.end()){
            ListNode * temp = head;
            head = head->next;
            delete temp; 
        }
        ListNode* curr = head;
        while(curr && curr->next){
            if(set.find(curr->next->val) != set.end()){
                ListNode * temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            }else{
                curr = curr->next;
            }
        }
        return head;
    }
};
