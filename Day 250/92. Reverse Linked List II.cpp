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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next) return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* prev = dummy;
        for(int i = 1; i<left; i++) prev = prev->next;

        ListNode* curr = prev->next;
        stack<ListNode*> st;

        for(int i = left; i<=right; i++){
            st.push(curr);
            curr= curr->next;
        }
        ListNode* rp = curr;
        while(!st.empty()){
            prev->next = st.top();
            st.pop();
            prev = prev->next;
        }
        prev->next = rp;
        return dummy->next;
    }
};