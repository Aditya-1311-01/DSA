class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int product=1;
        int div=n;

        while(n){
            sum+=(n%10);
            product*=(n%10);

            n/=10;
        }

        sum=sum+product;

        if(div%sum==0) return true;
        else return false;
        
    }
};