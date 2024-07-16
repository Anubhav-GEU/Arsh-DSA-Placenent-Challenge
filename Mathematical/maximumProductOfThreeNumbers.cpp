class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int third = INT_MIN, second = INT_MIN, first = INT_MIN;
        int firstMin = INT_MAX, secondMin = INT_MAX;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] < firstMin ){
                secondMin = firstMin;
                firstMin = nums[i];
            }
            else if (nums[i] < secondMin) {
                secondMin = nums[i];
            }
            if (nums[i] > third) {
                if (nums[i]>first) {
                    third = second;
                    second = first;
                    first = nums[i];
                }
                else if (nums[i] > second) {
                    third = second;
                    second = nums[i];
                }
                else {
                    third = nums[i];
                }
            }
        }
        return max(first*second*third,firstMin*secondMin*first);
    }
};
