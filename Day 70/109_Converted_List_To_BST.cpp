class Solution {
public:
    TreeNode* solve(ListNode *leftHead, ListNode *rightHead) {
        if (leftHead == rightHead)
            return nullptr;
        ListNode *slow = leftHead, *fast = leftHead;
        while (fast != rightHead && fast -> next != rightHead) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        TreeNode *root = new TreeNode(slow -> val);
        root -> left = solve(leftHead, slow);
        root -> right = solve(slow -> next, rightHead);
        return root;
    }   
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next== NULL){
            TreeNode* root = new TreeNode(head->val);
            return root;
        } 
        return solve(head, NULL);
    }
};