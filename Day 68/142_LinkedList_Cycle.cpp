/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // we will use set to store the address of nodes as set stores only unique data
        unordered_set<ListNode*> st;
        ListNode* tmp = head;

        while(tmp != NULL){
            // now check that if the node's address is present in set or not
            if(st.find(tmp) != st.end()) return tmp;
            else{
                st.insert(tmp);
                tmp = tmp->next;

            }
        }
        return NULL;
    }
};
// TC - O(N)
// SC - O(N)





// 2nd Approach
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        //base case
        if(head == NULL || head->next == NULL) return NULL;

        // using floyd's cycle algo
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* tmp = head;

        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
            // if both meets then there is a cycle present
            if(slow == fast){
                // it will find the nodes where the tail points to
                while(tmp != fast){
                    fast = fast->next;
                    tmp = tmp->next;
                }
                return tmp;
            }
        }
        return NULL;

    }
};
// TC - O(N)
// SC - O(1)