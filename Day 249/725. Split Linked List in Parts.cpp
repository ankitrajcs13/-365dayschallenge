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
        vector<ListNode*> res(k,NULL);

        ListNode* tmp = head;
        int len = 0;
        while(tmp){
            len++;
            tmp = tmp->next;
        }

        int parts = len/k;
        int remaining = len%k;

        tmp = head;
        int j = 0;
        while(tmp){
            ListNode* st= new ListNode();
            ListNode* curr = st;
            for(int i = 0; i<parts; i++){
                curr->next = new ListNode(tmp->val);
                tmp = tmp->next;
                curr = curr->next;
            }
            if(remaining>0){
                curr->next = new ListNode(tmp->val);
                tmp = tmp->next;
                curr = curr->next;
                remaining--;
            }
            res[j++] = st->next;
        }
        return res;
    }
};