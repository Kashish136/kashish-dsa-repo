class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        


       vector<vector<int>>output;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
             
            if( i > 0 && nums[i] == nums[i-1]) continue;

            for(int j = i+1 ; j < n ; j++){

                if(j > i+1 && nums[j] == nums[j-1]) continue;

                int k = j+1;
                int l = n-1;

                while( k < l){
                  
                  long long ans = nums[i];
                  ans += nums[j];
                  ans += nums[k];
                  ans += nums[l];

                  if(ans == target){
                    vector<int>key = {nums[i] , nums[j] , 
                    nums[k] , nums[l]};
                    output.push_back(key);
                    k++;
                    l--;

                    while( k < l && nums[k] == nums[k-1]) k++;
                    while(k < l && nums[l] == nums[l+1]) l--;
                  }

                  else if(ans < target){
                    k++;
                  }

                  else{
                    l--;
                  }


                }
            }
        }

        return output ;
    }
};