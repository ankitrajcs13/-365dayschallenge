class Solution {
public:
    int rev(string s){
        int maxi = s[0]-'0';
        
        for(int i = 0;i<s.length(); i++){
            int v= s[i] - '0';
            maxi = max(maxi,v);
        }
        return maxi;
        
        
    }
    int maxSum(vector<int>& nums) {
        int ankires = -1;
        
        for(int i = 0; i<nums.size()-1; i++){
            for(int j = i+1; j<nums.size(); j++){
                string a= to_string(nums[i]);
                string b= to_string(nums[j]);
                
                int av1 = rev(a);
                int av2 = rev(b);
                if(av1 == av2){
                    int sum = nums[i] + nums[j];
                    ankires = max(ankires,sum);
                }
            }
        }
        return ankires;
    }
};