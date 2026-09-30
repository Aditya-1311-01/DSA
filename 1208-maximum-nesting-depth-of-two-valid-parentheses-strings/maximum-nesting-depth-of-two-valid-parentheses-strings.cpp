class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        // half part mai divide krna hai
       //  (((()))) G0 and G1 mai aadha aadha divide krna hai
       // tbhi max(A,B) minimum possible value aaega
       int d=0;
       int n=seq.size();
       vector<int>result(n);

       for(int i=0;i<n;i++){
        if(seq[i]=='('){
            d++;

            result[i]=(d%2==0)?0:1;
        }
        else{
            result[i]=(d%2==0)?0:1;
            d--;
        }
       }

       return result;
        
    }
};