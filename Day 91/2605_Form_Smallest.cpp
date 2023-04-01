class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        
        map<int,int> AnkiMp;
        for(int it: nums1) AnkiMp[it]++;
        for(int it: nums2) AnkiMp[it]++;
        
        int AnMin1 = INT_MAX;
        for(int i = 0; i< nums1.size(); i++){
            if(nums1[i] < AnMin1) AnMin1 = nums1[i];
        }
        int AnMin2 = INT_MAX;
        for(int i = 0; i< nums2.size(); i++){
            if(nums2[i] < AnMin2) AnMin2 = nums2[i];
        }
        // so that if the same element is present in both we can return it easily.
        for(auto it:AnkiMp){
            if(it.second > 1)
                return it.first;
        }
        // now if both are different then we have to join to get a minimum number;
        string AnkRes;
        if(AnMin1 < AnMin2)
                AnkRes+= to_string(AnMin1) + to_string(AnMin2);
        else
            AnkRes+= to_string(AnMin2) + to_string(AnMin1);
        int ResAnki = stoi(AnkRes);
        return ResAnki;
        
    }
};