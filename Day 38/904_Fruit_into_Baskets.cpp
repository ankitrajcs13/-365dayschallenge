class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int last_fruit = -1;
        int sec_last_fruit = -1;
        int last_fruit_cnt = 0;
        int curr_max = 0;
        int maxi = 0;

        for(auto it: fruits){
            if(it == last_fruit || it == sec_last_fruit)
                curr_max +=1;
            else
                curr_max = last_fruit_cnt+1;
            if(it == last_fruit)
                last_fruit_cnt+=1;
            else
                last_fruit_cnt = 1;
            if(it != last_fruit){
                sec_last_fruit = last_fruit;
                last_fruit = it;
            }
            maxi = max(maxi, curr_max);
        }
        return maxi;
    }
};
// TC - O(N)
// SC - O(1)