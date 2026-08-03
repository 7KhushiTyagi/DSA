class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left = 0;
        double max_avg = -1e9;
        double sum = 0;

        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            if ((right - left + 1) > k) {
                sum -= nums[left];
                left++;
            }

            if ((right - left + 1) == k) {
                max_avg = max(max_avg, sum / k);
            }
        }

        return max_avg;
    }
};