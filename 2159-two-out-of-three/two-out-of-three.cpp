
class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1,
                              vector<int>& nums2,
                              vector<int>& nums3) {

        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        unordered_set<int> s3(nums3.begin(), nums3.end());

        unordered_set<int> ans;

        for (int x : s1) {
            if (s2.count(x) || s3.count(x)) {
                ans.insert(x);
            }
        }

        for (int x : s2) {
            if (s3.count(x)) {
                ans.insert(x);
            }
        }

        return vector<int>(ans.begin(), ans.end());
    }
};
