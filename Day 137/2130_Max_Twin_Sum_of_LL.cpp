// using vectorrs

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
    int pairSum(ListNode* head) {
        vector<int> res;

        ListNode* tmp = head;

        while(tmp){
            res.push_back(tmp->val);
            tmp = tmp->next;
        }
        // using two pointer approach to get twin
        
        int i = 0, j = res.size()-1, ans = 0;
        while(i<j){
            ans = max(ans, res[i] + res[j]);
            i++,j--;
        }


        return ans;
    }
};

//using stack
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
    int pairSum(ListNode* head) {
        stack<int> st;

        ListNode* tmp = head;

        while(tmp){
            st.push(tmp->val);
            tmp = tmp->next;
        }
        tmp = head;

        int i = 1, size = st.size();
        int res = 0;
        while(i <= size/2){
            res = max(res, tmp->val + st.top());
            tmp = tmp->next;
            st.pop();
            i++;
        }
        return res;

        
    }
};


// in o(1) Space 

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
    int pairSum(ListNode* head) {
        int res = 0;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        // slow is pointing to mid of list
        // reverse the list from mid
        ListNode *prev = NULL, *next = NULL;
 
        while (slow != NULL) {
            // Store next
            next = slow->next;
            // Reverse current node's pointer
            slow->next = prev;
            // Move pointers one position ahead.
            prev = slow;
            slow = next;
        }

        ListNode* st = head;
        while(prev){
            res = max(res, st->val + prev->val);
            prev = prev->next;
            st = st->next;
        }
        return res;
    }
};