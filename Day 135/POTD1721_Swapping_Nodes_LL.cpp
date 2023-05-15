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
    ListNode* swapNodes(ListNode* head, int k) {
        
        int len = 0;
        ListNode* tmp = head;
        while(tmp != NULL){
            len++;
            tmp = tmp->next;
        }
        ListNode* fst = head;
        ListNode* lst = head;
        int i = 1;
        while( i< k){
            fst = fst->next;
            i++;
        }
        len = len+1-k;
        i=1;
        while( i< len){
            lst = lst->next;
            i++;
        }
        int t = fst->val;
        fst->val = lst->val;
        lst->val = t;
        return head;

    }
};