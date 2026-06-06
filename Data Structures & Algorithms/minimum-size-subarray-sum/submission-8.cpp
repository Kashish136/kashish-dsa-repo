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
                output = min(output , (right-left+1));
                sum -= nums[left];
                left++;
                
            }

        }

        return output == INT_MAX ? 0 : output ;
    }
};