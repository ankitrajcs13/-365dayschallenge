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
    int gcd(int a, int b)
{
    int result = ((a < b) ? a : b);
    while (result > 0) {
        if (a % result == 0 && b % result == 0) {
            break;
        }
        result--;
    }
    return result;
}
    
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        
        ListNode* tmp = head;
        ListNode* nextP = tmp->next;
        while(tmp->next != NULL){
            int a = tmp->val, b= nextP->val;
            int gcdV = gcd(tmp->val, nextP->val);
            ListNode* node = new ListNode(gcdV);
            
            tmp->next = node;
            node->next = nextP;
            tmp = nextP;
            nextP = tmp->next;
        }
        return head;
        
    }
};