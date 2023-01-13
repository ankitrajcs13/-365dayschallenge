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

// using Recursion
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
      

        while(head != NULL && head->val == val){
            // deleting the element from the string
            head = head->next;
        }
          if(head == NULL)
            return head;
        // recursion
        head->next = removeElements(head->next,val);
        return head;

    }
};


// 2nd Approach - Iterative
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
    ListNode* removeElements(ListNode* head, int val) {
        // creating a dummy node so that we can have a prev pointer.
        // because if we have to delete the first pointer we need a prev node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prev = dummy;
        ListNode* curr = head;
        
        while(curr != NULL)
        {
            if(curr->val == val)
                // pointing the prev element to the the next element
                // so that the element should be deleted
                prev->next = curr->next;
            else
                prev = curr;
            curr = curr->next;
        }
        
        return dummy->next;

    }
};