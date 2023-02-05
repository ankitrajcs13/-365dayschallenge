class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        // we will use set to store the occurence
        set<int> my_st;
        for(auto &it: banned)
            my_st.insert(it);
        int myans= 0, mysum = 0;
        for(int i = 1; i <=n ; i++){
            // now check that which element is present from 1 to n
            if(my_st.find(i) == my_st.end()){
                // means that it is not in the set
                myans++;
                // update sum
                mysum +=i;
                // and if maxSum is <=0 then break
                if(mysum > maxSum){
                    myans--;
                    break;
                }
            }
        }
        return myans;
        
    }
};