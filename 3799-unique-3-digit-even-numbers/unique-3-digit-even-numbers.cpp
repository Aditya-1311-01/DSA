class Solution {
public:
    int ans = 0;

    void solve(vector<int>& digits, vector<bool>& used,
               int pos, int num) {

        if (pos == 3) {
            ans++;
            return;
        }

        bool taken[10] = {false};

        for (int i = 0; i < digits.size(); i++) {

            if (used[i])
                continue;

            int d = digits[i];

            // Same digit ko same level par dobara try nahi karna
            if (taken[d])
                continue;

            // First digit 0 nahi ho sakta
            if (pos == 0 && d == 0)
                continue;

            // Last digit even hona chahiye
            if (pos == 2 && d % 2 != 0)
                continue;

            taken[d] = true;
            used[i] = true;

            solve(digits, used, pos + 1, num * 10 + d);

            used[i] = false;
        }
    }

    int totalNumbers(vector<int>& digits) {
        vector<int>map(10,0);
        int ans=0;

        for(int i=0;i<digits.size();i++){
            map[digits[i]]++;
        }

        for(int i=1;i<=9;i++){
            if(map[i]==0) continue;
            map[i]--;
            for(int j=0;j<=9;j++){
                if(map[j]==0) continue;
                map[j]--;
                for(int k=0;k<=8;k+=2){
                    if(map[k]==0) continue;

                    map[k]--;
                    ans++;

                    map[k]++;


                }
                map[j]++;
            }
            map[i]++;
        }

        return  ans;
    }
};