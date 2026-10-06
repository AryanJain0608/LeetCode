class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        set<int> s;

        // Put all elements of nums1 into the set
        for (int i = 0; i < nums1.size(); i++) {
            s.insert(nums1[i]);
        }

        vector<int> ans;

        // Check which elements of nums2 are present in the set
        for (int i = 0; i < nums2.size(); i++) {

            if (s.find(nums2[i]) != s.end()) {
                ans.push_back(nums2[i]);

                // Remove it so we don't add it again
                s.erase(nums2[i]);
            }
        }

        return ans;
    }
};