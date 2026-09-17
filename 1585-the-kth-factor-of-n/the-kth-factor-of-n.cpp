class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int>factor;
        for(int i=1;i<=n;i++){
            if(n%i==0){
                factor.push_back(i);
            }
            
        }

        if(factor.size()<k)
        return -1;

        int ans=factor[k-1];
        return ans;
        
    }
};