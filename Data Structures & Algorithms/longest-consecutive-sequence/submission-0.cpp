class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
      unordered_set<int>st(nums.begin() , nums.end());
      int output = 1;

      for( int i = 0 ; i < nums.size() ; i++){
          int num = nums[i];

          int count = 0;
          while(num > 0 && (st.find(num-1) != st.end())){
             count++;
             num--;
          }

          output = max(output , count);

      }

      return output ;

    }
};
