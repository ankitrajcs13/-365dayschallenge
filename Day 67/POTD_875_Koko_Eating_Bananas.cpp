class Solution {
private:
    bool canEatBananas(vector<int> &p,int h,int mid){
        long ans=0;
        for(int i=0;i<p.size();i++){
            ans+=(p[i]+mid-1)/mid;
        }return  ans<=h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
         int i=1;
        int j=*max_element(piles.begin(),piles.end());
        int ans=j;
        while(i<=j){
            int mid=(i+j)/2;
            if(canEatBananas(piles,h,mid)){
                ans=mid;
                j=mid-1;
            }
            else i=mid+1;
        }
        return ans;
        
        
    }
};