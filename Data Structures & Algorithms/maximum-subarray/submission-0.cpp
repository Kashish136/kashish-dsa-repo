class Solution {
public:
    int maxSubArray(vector<int>& nums) {
          

          int ans = INT_MIN;
          int sum = 0;

            for(int i = 0 ; i < nums.size() ; i++){
              
              int value = nums[i];
              if(sum < 0){
                 sum = 0;
                }

              else{
                 sum += nums[i];
                 ans = max(ans , sum);
                }
            }

        return sum ;
    }
};
