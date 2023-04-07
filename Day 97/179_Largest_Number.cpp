class Solution {
private:
    static bool compare(string a, string b) {
        return a+b > b+a;
    }
public:
    string largestNumber(vector<int>& nums) {


        vector<string> v;
        for(int i = 0; i<nums.size(); i++){
            v.push_back( to_string(nums[i]));
        }
        sort(v.begin(), v.end(), compare);
        bool tr = true;

         if(v[0] == "0") return "0";

        string st = "";
        for(int i = 0; i<v.size(); i++){
            st += v[i];
        }
        return st;

    }
};