class Solution {
public:
    long long sumAndMultiply(int n) {
        
        
        int ans=0;
        int sum=0;
        int rev=0;
        while(n){
            int x=n%10;
            if(x!=0){
                rev=rev*10+x;
                sum+=x;
            }
            n/=10;

        }
        int rev1=0;
        while(rev){
            int y=rev%10;
            rev1=rev1*10+y;
            rev=rev/10;
        }

        return (long long)rev1*sum;
        
    }
};