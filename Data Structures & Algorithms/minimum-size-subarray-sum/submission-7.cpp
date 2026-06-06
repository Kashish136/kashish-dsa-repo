class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int left = 0;
        int output = INT_MAX;
        int sum = 0;
        

        for(int right = 0 ; right < nums.size() ; right++){
            int num = nums[right];
            sum += num;

            while(left <= right && sum >= target){
                sum -= nums[left];
                left++;
                output = min(output , (right-left+1));
            }

        }

        return output == INT_MAX ? 0 : output ;
    }
};