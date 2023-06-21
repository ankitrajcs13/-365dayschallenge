class Solution {
public:
    long long c(long long val ,vector<pair<long long,long long>>&vp){
        long long sum = 0;
        for(int i=0;i<vp.size();i++){
            sum += abs(val-vp[i].first)*vp[i].second;
        }
        return sum;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        vector<pair<long long,long long>>vp;
         long long weight = 0;
        for(int i=0;i<nums.size();i++){
            vp.push_back({nums[i],cost[i]});
            weight += cost[i];
        }
       long long l=*min_element(nums.begin(),nums.end());
       long long r=*max_element(nums.begin(),nums.end());
       long long ans=l;
        while(l<r){
            long long mid=(l+r)/2;
            long long c1=c(mid,vp);
            long long c2=c(mid+1,vp);
            if(c1>c2){
                l = mid+1;
                ans = l;
            }   
            else{
                r = mid;
                ans = r;
            }
        }
        return c(ans,vp);
    }
};