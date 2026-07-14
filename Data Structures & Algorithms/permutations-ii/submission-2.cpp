class Solution {
public:

    
 void backtracking( vector<int>&nums , int index , int n , set<vector<int>>&st){
         
         if(index == n){
           st.insert(nums);
            return ;
         }

         for( int i = index ; i < n ; i++){
            swap(nums[i] , nums[index]);
            backtracking( nums , index+1 , n ,st);
            swap( nums[i] , nums[index]);
        }
 }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        set<vector<int>>st;
        int n = nums.size();
        backtracking(nums , 0 , n , st);
        vector<vector<int>>ans(st.begin() , st.end());
        return ans ;
    }
};