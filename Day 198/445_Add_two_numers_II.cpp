// using Stack
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1,st2;

        while(l1 != NULL){
            st1.push(l1->val);
            l1 = l1->next;
        }
        while(l2 != NULL){
            st2.push(l2->val);
            l2 = l2->next;
        }
        ListNode* res = new ListNode();

        int tsum = 0, carry = 0;
        while(!st1.empty() || !st2.empty()){
            if(!st1.empty()){
                int d = st1.top();
                st1.pop();
                tsum += d;
            }
            if(!st2.empty()){
                int d = st2.top();
                st2.pop();
                tsum += d;
            }
            res->val = tsum%10;
            carry = tsum/10;
            ListNode* nNode = new ListNode(carry);
            nNode->next = res;
            res = nNode;
            tsum = carry;
        }
        if(carry == 0) return res->next;
        return res;
    }
};



// using Reverse
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

    ListNode* reverseLL(ListNode* head){
        ListNode* prev = NULL;
        ListNode* tmp;

        while(head){
            // to track the next node
            tmp = head->next;

            //reverse the link
            head->next = prev;

            // update the pointers
            prev = head;
            head = tmp;

        }
        return prev;


    }


    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         ListNode* r1 = reverseLL(l1);
        ListNode* r2 = reverseLL(l2);

        int totalSum = 0;
        int carry = 0;
        ListNode* ans = new ListNode();
        while (r1 || r2) {
            if (r1) {
                totalSum += r1->val;
                r1 = r1->next;
            }
            if (r2) {
                totalSum += r2->val;
                r2 = r2->next;
            }

            ans->val = totalSum % 10;
            carry = totalSum / 10;
            ListNode* head = new ListNode(carry);
            head->next = ans;
            ans = head;
            totalSum = carry;
        }
         return carry == 0 ? ans->next : ans;
    }
};