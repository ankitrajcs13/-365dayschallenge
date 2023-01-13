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
    ListNode* oddEvenList(ListNode* head) {

        // base case
        if(!head || !(head->next) || !(head->next->next))  //base case
            return head;
        
        ListNode* head1 = head;
        ListNode* head2 = head->next;
        ListNode* even = head->next;
        while(head1->next && head2->next){
            head1->next = head2->next; // pointing odd to next odd node
            head1 = head1->next;

            head2->next = head1->next;// pointing even to next even node
            head2 = head2->next;

        }
       
        head1->next = even;

        return head;


    }
};

// TC - O(n)
// SC - O(1)