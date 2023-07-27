class Solution {
public:

    bool isPos(vector<int>& batteries,  long long time, int n){
         long long tottime = 0;

        for(int it: batteries){
            if(it< time) tottime+=it;
            else tottime+=time;
        }
        return (tottime >= time*n);

    }

    long long maxRunTime(int n, vector<int>& batteries) {
        // applying binary search
        long long low = 0, high = 1e14;
        long long ans = 0;
        while(low<=high){
            long long mid = low + (high-low)/2;

            if(isPos(batteries,mid,n)){
                ans = mid;
                low = mid+1;
            }
            else 
                high = mid-1;
        }
        return ans;
    }
};