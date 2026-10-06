class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums,
                                      vector<int>& queries,
                                      int x) {

        vector<int> positions;

        // Find all positions of x
        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] == x) {
                positions.push_back(i);
            }
        }

        vector<int> ans;

        // Answer each query
        for (int i = 0; i < queries.size(); i++) {

            int occurrence = queries[i];

            // Check if this occurrence exists
            if (occurrence <= positions.size()) {
                ans.push_back(positions[occurrence - 1]);
            }
            else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};