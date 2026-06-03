class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
     if(nums.empty()){
        return 0;
     }
      unordered_set<int>st(nums.begin() , nums.end());
      int output = 1;

      for( int i = 0 ; i < nums.size() ; i++){
          int num = nums[i];

          int count = 1;
          while((st.find(num-1) != st.end())){
             count++;
             num--;
          }

          output = max(output , count);

      }

      return output ;

    }
};
