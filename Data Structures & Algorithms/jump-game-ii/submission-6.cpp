class Solution {
public: 
    
    int helper(vector<int>&nums , int index){
     int n = nums.size();

    if(index == n - 1)
        return 0;

    int ans = INT_MAX;

    int farthest = min(n - 1, index + nums[index]);

    for(int i = index + 1; i <= farthest; i++) {
        int jumps = helper(nums, i);

        if(jumps != INT_MAX)
            ans = min(ans, 1 + jumps);
    }

    return ans;
}


    int jump(vector<int>& nums) {
        return helper(nums , 0);
    }
};
