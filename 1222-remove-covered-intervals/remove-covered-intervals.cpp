class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        int ans = intervals.size();

        sort(intervals.begin(), intervals.end(),
            [](vector<int>& a, vector<int>& b){
                if(a[0] == b[0])
                    return a[1] > b[1];
                return a[0] < b[0];
            });

        int start1 = intervals[0][0];
        int end1 = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++){

            int s2 = intervals[i][0];
            int e2 = intervals[i][1];

            if(e2 <= end1){   // Covered interval
                ans--;
                continue;
            }

            start1 = s2;
            end1 = e2;
        }

        return ans;
    }
};