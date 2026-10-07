class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int n = s2.size();
        int k = s1.size();

        if (k > n)
            return false;

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        for (char ch : s1) {
            freq1[ch - 'a']++;
        }

        int i = 0, j = 0;

        while (j < n) {

            
            freq2[s2[j] - 'a']++;

            if (j - i + 1 == k) {

                
                if (freq1 == freq2)
                    return true;

                
                freq2[s2[i] - 'a']--;
                i++;
            }

            j++;
        }

        return false;
    }
};