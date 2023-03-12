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

    ListNode* merge(ListNode* a, ListNode* b){
        // create one dummy node to track the pointer
        ListNode* dummy = new ListNode(-1);
        ListNode* tmp = dummy;
        while(a != NULL && b!= NULL ){
            if( a->val <  b->val){
                tmp->next = a;
                a = a->next;
                tmp = tmp->next;
            }
            else{// it means b is having smaller node
                tmp->next = b;
                b = b ->next;
                tmp = tmp->next;
            }
        }
        // now check for all the remaining nodes of a
        while(a != NULL){
            tmp ->next = a;
            a = a->next;
            tmp = tmp->next;
        }
        // now check for all the remaining nodes of b
        while(b != NULL){
            tmp ->next = b;
            b = b->next;
            tmp = tmp->next;
        }
        return dummy->next;
    }
    ListNode* sortNodes(vector<ListNode*>& lists, int st, int end){
        if(st == end)
            return lists[st];
        int mid = st + (end - st)/2;
        // Now apply recursion
        ListNode* a = sortNodes(lists,st,mid);
        ListNode* b = sortNodes(lists,mid+1,end);
        return merge(a,b); 

    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        return sortNodes(lists,0, lists.size()-1);

    }
};