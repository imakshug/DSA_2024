//2326. Spiral Matrix IV

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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> resMat(m, vector<int>(n, -1));
        int topC = 0;
        int topR = 0;
        int botC = n-1;
        int botR = m-1;
        
        ListNode* temp = head;

        while(temp !=NULL){

            //first row:-
            for(int i=topC; temp !=NULL && i<=botC; i++){
                resMat[topR][i] = temp->val;
                temp = temp->next;
            }

            topR++;

            //last col:-
            for(int j=topR; temp !=NULL && j<=botR; j++){
                resMat[j][botC] = temp->val;
                temp = temp->next;
            }

            botC--;

            for(int k=botC; temp !=NULL && k>=topC; k--){
                resMat[botR][k] = temp->val;
                temp = temp->next;
            }

            botR--;

            for(int l=botR; temp !=NULL && l>=topR; l--){
                resMat[l][topC] = temp->val;
                temp = temp->next;
            }

            topC++;

        }

        return resMat;
    }
};
