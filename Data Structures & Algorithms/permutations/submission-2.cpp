class Solution {
public:  

    void helper( int index , vector<int>&nums , int n , vector<vector<int>>&output ){

    if(index == nums.size()){
        output.push_back(nums);
        return ;
    }

    for( int i = index ; i < n ; i++){

        swap(nums[i] , nums[index]);
        
        helper(index+1 , nums , n , output);
        swap(nums[i] , nums[index]);

    }

}
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>>output ;
        int n = nums.size();
        helper(0 , nums , n , output);
        return output ;
    }
};
