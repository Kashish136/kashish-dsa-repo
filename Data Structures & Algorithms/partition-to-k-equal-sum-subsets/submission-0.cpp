class Solution {
public:



    
 bool helper( vector<int>&nums , vector<int>&visited , int target , int current_sum , int i , int k){


       if( k == 1){
        return true ;
       }

       if( current_sum == target){
          return helper(nums , visited , target , 0 , 0 , k-1);
       }


       for( int j = i ; j < nums.size() ; j++){

            if(visited[j] || (current_sum + nums[j]) > target){
                continue ;
            }

            visited[j] = true ;

if(helper(nums , visited , target , current_sum + nums[j] , j+1 , k)){
    return true ;
}


visited[j] = false ;
       }

       return false ;
 }


    bool canPartitionKSubsets(vector<int>& nums, int k) {
        

        int sum = accumulate(nums.begin(), nums.end(), 0);

    if (nums.size() < k || sum % k) return false;

    sort(nums.rbegin(), nums.rend()); // optimization

    vector<int> visited(nums.size(), false);

    return helper(nums, visited, sum / k, 0, 0, k);
    }
};