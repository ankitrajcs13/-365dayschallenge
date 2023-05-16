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
    ListNode* swapPairs(ListNode* head) {
        // edge case
        if(head == NULL || head->next == NULL) return head;


        ListNode* tmp = head->next;
        // pointing to next alternate element to solve using recursion
        head->next = swapPairs(head->next->next);
        // to swap element
        tmp->next = head; 
        // and then tmp will act as head
        return tmp;
    }
};


// iterative

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
    ListNode* swapPairs(ListNode* head) {
        //edge case
        if(head == NULL || head->next == NULL) return head;
        ListNode* dum = new ListNode();

        ListNode* prev = dum;
        ListNode* curr = head;

        while(curr && curr->next){
            prev->next = curr->next;
            curr->next = prev->next->next;
            prev->next->next = curr;

            // updating both pointers
            prev = curr;
            curr = curr->next;
        }
        return dum->next;
    }
};