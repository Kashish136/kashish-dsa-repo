class Solution {
public:
   

     int helper(vector<int>& nums, int n, int left, int right) {

        int prev2 = 0;
        int prev1 = 0;

        for (int i = left; i <= right; i++) {

            int pick = nums[i] + prev2;
            int notpick = prev1;

            int current = max(pick, notpick);

            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }

    
    int rob(vector<int>& nums) {

        int n = nums.size();
        if( n == 1){
            return nums[0];
        }

        if( n == 0){
            return 0 ;
        }

        // vector<int>dp(n , -1);
        // vector<int>dp2(n,-1);

        int key = helper(nums , n , 0 , n-2 );
        int key2 = helper(nums , n , 1 , n-1 );

        return max(key , key2);
        
    }
};
