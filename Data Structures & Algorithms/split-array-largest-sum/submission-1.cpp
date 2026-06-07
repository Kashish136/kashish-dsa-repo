class Solution {
public:
 

   bool helper(vector<int>&nums , int k , int mid){
     
     int count = 1;
     int allocated = 0;

     for(int i = 0 ; i < nums.size() ; i++){
        if((allocated + nums[i]) <= mid){
            allocated += nums[i];
        }
        else{
            count++;
            allocated = nums[i];
        }
     }

     return (count <= k);
    }

    int splitArray(vector<int>& nums, int k) {
        
        int low = *max_element(nums.begin() , nums.end());
        int high = accumulate(nums.begin(), nums.end() , 0);

        while(low <= high){
            int mid = low + (high-low)/2;
            if(helper(nums , k , mid)){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return low;
    }
};