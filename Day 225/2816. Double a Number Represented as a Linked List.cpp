class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        vector<int> v1;
        ListNode* t1 = head;
        while(t1){
            v1.push_back(t1->val);
            t1 = t1->next;
        }
        vector<int> v2;
        int rem = 0;
        for(int i= v1.size()-1; i>=0; i--){
            int val = v1[i];
            val = val *2;
            val += rem;
            string p = to_string(val);
            if(p.size() == 2){
                v2.push_back(p[1] - '0');
                rem = p[0]-'0';
            }
            else{
                v2.push_back(p[0] - '0');
                rem = 0;
            }
        }
        if(rem > 0) v2.push_back(rem);
        
        reverse(v2.begin(), v2.end());
        
        ListNode* d1 = new ListNode();
        head = d1;
        for(int i =0; i<v2.size(); i++){
            ListNode* i1 = new ListNode();
            int v1= v2[i];
            i1->val = v1;
            d1->next = i1;
            d1 = i1;
        }
        return head->next;
    }
};