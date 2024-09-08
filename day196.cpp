//125. Split Linked List in Parts

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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0; // variable to store length of linked list
        ListNode* trav = head; // init traverser
        // Traverse linked list
        while(trav) {
            n+=1;
            trav=trav->next;
        }
        // find req block size
        int reqBlockSize = max(n/k,1);
        // check if there will be reaming nodes
        int remaining = n%k;
        // vector to store output
        vector<ListNode*> out;
        // counter to count number of nodes we have touched
        int c = 0;
        while(head){
            // temp linked list to get elements in final vector
            ListNode* temp = new ListNode();
            // pointer to above node
            ListNode* outTemp = temp;
            // fist add in reqBlockSize elements
            for(int i=0; i<reqBlockSize; i++) {
                temp->next = new ListNode(head->val);
                head = head->next;
                temp = temp->next;
                c+=1;
            }
            // check if we need to add in extra elements
            // also make sure we don't add in extra elemets when n>k
            if(remaining>0 && n>k){
                temp->next = new ListNode(head->val);
                head = head->next;
                temp = temp->next;
                c+=1;
                remaining-=1;
            }
            // push linked list into output vector
            out.push_back(outTemp->next);
        }
        // loop until we have k blocks
        while(c<k){
            out.push_back(NULL);
            c++;
        }
        return out;
    }
};



