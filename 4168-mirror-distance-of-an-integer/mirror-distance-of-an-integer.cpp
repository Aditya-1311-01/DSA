class Solution {
public:
    int reverse(int n){
        int ans=0;
        while(n){
            int x=n%10;
            n/=10;
            ans=(ans*10)+x;
        }
        return ans;
    }
    int mirrorDistance(int n) {

        int x=reverse(n);
        int ans=abs(n-x);

        return ans;
    }
};