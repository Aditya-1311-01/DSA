class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum=0;
        int i=0,j=0;
        int ans=0;
        int n=arr.size();

        while(j<n){
            sum+=arr[j];

            if(j-i+1==k){
                int avg=sum*1.0/k;
                if(avg>=threshold){
                    ans+=1;
                }
                sum-=arr[i];
                i++;
            }
            j++;
        }

        return ans;



        
    }
};