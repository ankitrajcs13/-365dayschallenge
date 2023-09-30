class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int>ankimp;
        for(auto it: nums){
            ankimp[it]++;
        }
        int cnt = 0, ankifl = 0;
        for(auto it:ankimp){
            int node = it.second;
            if(node < 2) return -1;
            // it will take care of odd as well as even 
            cnt += (node+2)/3;
            cout<<cnt<<endl;
        }
        // if(ankifl) return -1;
        return cnt;
    }
};