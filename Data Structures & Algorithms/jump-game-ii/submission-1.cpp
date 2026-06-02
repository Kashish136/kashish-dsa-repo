class Solution {
public: 
    
    int helper(vector<int>&nums , int index){
    if( index >= nums.size()){
        return 0 ;
    }

    // if we have reached the final index we must return 0 as an answer 

    int value = INT_MAX;
    
    int key = min(nums.size()-1 , (index+nums[index]));

    for( int i = index+1 ; i <= key ; i++){
        value = min(value , (1+helper(nums , i)))
    }

    return value;
}


    int jump(vector<int>& nums) {
        return helper(nums , 0);
    }
};
