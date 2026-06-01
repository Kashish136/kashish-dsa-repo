class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int n = nums.size();
        int ans = INT_MIN;

        for( int i = 0 ; i < n ; i++){
            int currentsum = 0;
        for(int j = i ; j < n ; j++){

            currentsum += nums[j%n];
            ans = max(ans , currentsum);

        }
        }

        return ans ;
    }
};