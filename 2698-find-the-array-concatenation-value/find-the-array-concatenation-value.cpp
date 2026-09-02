class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long ans = 0;
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int multiplier = 1;
            int temp = nums[right];

            while (temp > 0) {
                multiplier *= 10;
                temp /= 10;
            }

            ans += nums[left]*multiplier + nums[right];

            left++;
            right--;
        }

        if (left == right) {
            ans += nums[left];
        }

        return ans;
    }
};