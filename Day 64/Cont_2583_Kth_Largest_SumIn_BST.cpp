class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        // using BFS traversal to traverse level wise
        queue<TreeNode*> my_q;
        my_q.push(root);
        vector<long long> my_ans;
        while(!my_q.empty()){
            int anki_s = my_q.size();
            long long lev_sum = 0;
            for(int i = 0; i<anki_s; i++){
                auto tmp = my_q.front();
                my_q.pop();
                lev_sum += tmp->val;
                if(tmp->left) my_q.push(tmp->left);
                if(tmp->right) my_q.push(tmp->right);
                
            }
            my_ans.push_back(lev_sum);
        }
        sort(my_ans.begin(), my_ans.end());
        
        if(my_ans.size() < k) return -1; // take care of edge case
        else return my_ans[my_ans.size()-k];       
    }
};