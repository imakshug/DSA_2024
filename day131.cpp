// Find the Minimum and Maximum Number of Nodes Between Critical Points

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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* i = head, *j, *k;
        if (i->next) j = i->next;
        else return {-1,-1};
        if (j->next) k = j->next;
        else return {-1,-1};
        vector<int> idx;
        int curr_idx = 1;
        while (k){
            int x= i->val, y=j->val, z=k->val;
            if ((y<x && y<z)||(y>x && y>z)) idx.push_back(curr_idx);
            i = i->next;
            j = j->next;
            k = k->next;
            curr_idx++;
        }
        if (idx.size()<=1) return {-1,-1};
        int mi = INT_MAX;
        for (int t = 0; t < idx.size()-1; t++) mi = min(mi, idx[t+1]-idx[t]);
        return {mi, idx.back()-idx[0]};
    }
};
