class Solution {
public:
    int minSizeSubarray(vector<int>& v, int k) {
        int n=v.size();
        long long s=0;
        for(auto i:v)
            s=s+i;
        if(k%s==0)
            return (k/s)*n;
        long long x=(long long)(k/s)*n;
        k=k-(s*(k/s));
        for(int i=0;i<n;i++)
            v.push_back(v[i]);
        n=v.size();
        int i=0,j=0;
        s=0;
        int ans=INT_MAX;
        while(i<n && j<n)
        {
            s=s+v[j];
            while(i<n && s>k)
            {
                s=s-v[i];
                i++;
            }
            while(i<n && s==k)
            {   
                ans=min(ans,j-i+1);
                s=s-v[i];
                i++;
            }
            j++;
        }
        return ans+x;
    }
};