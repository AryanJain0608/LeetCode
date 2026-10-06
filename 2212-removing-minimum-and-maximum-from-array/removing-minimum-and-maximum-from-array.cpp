class Solution {
public:
    int minimumDeletions(vector<int>& nums) {

        int n = nums.size();

        int minValue = nums[0];
        int maxValue = nums[0];

        for (int i = 0; i < n; i++) {

            if (nums[i] < minValue) {
                minValue = nums[i];
            }

            if (nums[i] > maxValue) {
                maxValue = nums[i];
            }
        }

        int minIndex = 0;
        int maxIndex = 0;

        for (int i = 0; i < n; i++) {

            if (nums[i] == minValue) {
                minIndex = i;
            }

            if (nums[i] == maxValue) {
                maxIndex = i;
            }
        }

        int left = min(minIndex, maxIndex);
        int right = max(minIndex, maxIndex);

        int removeFromLeft = right + 1;

        int removeFromRight = n - left;

        int removeFromBoth = (left + 1) + (n - right);

        return min(removeFromLeft,
                   min(removeFromRight, removeFromBoth));
    }
};