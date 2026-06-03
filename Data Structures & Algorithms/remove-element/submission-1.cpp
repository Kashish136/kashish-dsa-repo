class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int i = 0;
        vector<int>output

        for( int j = 0 ; j < nums.size() ; j++){
            if(nums[j] == val){
                continue;
            }
            else{
                output[i] = nums[j];
                i++;
            }
        }

        return output.size();
    }
};