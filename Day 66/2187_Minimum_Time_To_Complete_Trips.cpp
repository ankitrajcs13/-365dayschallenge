class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(),time.end());
        long long st = 0;
        long long end = 1e14;
        // Applying binary search
        while(st <= end){
            long long tTrips = 0;
            long long mid = st + (end - st)/2;
            for(int i = 0; i<time.size(); i++)
                tTrips += mid/time[i];
            if(tTrips < totalTrips ) st = mid+1;
            else end = mid-1;
            
        }
        return st;

    }
};