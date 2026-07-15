class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int maxposition = 0;
        for(int i = 0 ; i < nums.size() ; i++){
           
            if( i > maxposition){
             return false ;
            }

            maxposition = max(maxposition , (i+nums[i]));
        }
       return true;
    }
};
