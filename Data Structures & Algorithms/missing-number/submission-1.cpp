class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int output = 0;
        int n = nums.size();
        for(int i = 0 ; i < nums.size() ; i++){
            output = output^i;
            output = output^nums[i];
        }
        output = output^n;

        return output;
    }
};
