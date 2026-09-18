class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n=s.length();

        vector<int>start(26,-1);
        vector<int>end(26,-1);
        vector<bool>isValid(26,true);

        vector<string> result;

        for(int i=0;i<n;i++){
            int idx=s[i]-'a';

            if(start[idx]==-1){
                start[idx]=i;
            }

            end[idx]=i;
        }
        // check kr rhe hain uss char se substring possible hai ya nhi 
        for(int c=0;c<26;c++){
            if(start[c]==-1) continue;

            for(int i=start[c];i<=end[c];i++){

                if(start[s[i]-'a']<start[c]){
                    isValid[c]=false;
                    break;
                }

                end[c]=max(end[c],end[s[i]-'a']);

                
            }
            
        }

        // small length substring lena hai tho uske liye hum piche se start krenge kyoki jiska start pehle milega tho wo chota substring hoga->greedy

        int lasttakenstart=INT_MAX;

        for(int i=n-1;i>=0;i--){
            int idx=s[i]-'a';

            if(!isValid[idx]) continue;

            if(i==start[idx] && end[idx]<lasttakenstart) { // check non overlapping
                result.push_back(s.substr(i,end[idx]-i+1));
                lasttakenstart=i;
            }
        }

        return result;
    }
};