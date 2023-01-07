class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int total_gas=0,total_cost=0;
        int curr_gas=0, spoint=0;
        for(int i=0;i<n;i++)
        {
            //these two variable are to check if no case is possible
            total_gas+=gas[i];
            total_cost+=cost[i];
            
            // to check that we can go with this fuel to next station or not
            curr_gas+=gas[i]-cost[i];
            // if it it negative, which means we cannot go
            if(curr_gas<0)
            {
               //there is a breakdown....so we will start from next point or index
                spoint=i+1;
                //reset our fuel 
                curr_gas=0;
            }
        }
        if(total_gas< total_cost)
            return -1;
        return spoint;
        
    }
};

// TC- O(N)
// SC- O(1)