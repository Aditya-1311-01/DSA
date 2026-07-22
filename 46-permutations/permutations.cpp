class Solution {
public:
    vector<vector<int>> ans;
    unordered_set<int> st;
    int n;


    void per(vector<int>& temp, vector<int> arr) {
        if(temp.size() == n){
            ans.push_back(temp);
            return ;
        }
        for (int i = 0; i < n; i++) {
            if(st.find(arr[i]) == st.end()){
                temp.push_back(arr[i]);
                st.insert(arr[i]);

                per(temp,arr);

                temp.pop_back();
                st.erase(arr[i]);
            }  
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        n = nums.size();
        per(temp, nums);
        return ans;
    }
};