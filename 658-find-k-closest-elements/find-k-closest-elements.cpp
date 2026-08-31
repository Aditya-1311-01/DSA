class Solution {
 public:
     vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        int n = arr.size();

        vector<pair<int, int>> temp;

        for(int i = 0; i < n; i++) {

            int diff = abs(arr[i] - x);

             temp.push_back({diff, arr[i]});
        }
        sort(temp.begin(), temp.end());

        vector<int> ans;

        for(int i = 0; i < k; i++) {
            ans.push_back(temp[i].second);
        }

        sort(ans.begin(), ans.end());

       return ans;
    }
 };
