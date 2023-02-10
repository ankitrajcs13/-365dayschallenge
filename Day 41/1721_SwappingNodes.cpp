class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
         ListNode* temp=head;
        int length=0;
        while(temp) {
            temp=temp->next;
            length++;
        }
        length=length+1-k;
        // edge case
        if(length==k) 
            return head;
        temp=head;
        int count=1;
        ListNode* fst=NULL;
        ListNode* snd=NULL;
        while(temp) {
            if(k==count) fst=temp;
            if(length==count) snd=temp;
            temp=temp->next;
            count++; 
        }
        int tp=fst->val;
        fst->val=snd->val;
        snd->val=tp;
        return head;
    }
};