class Solution {
public:
  
void helper(int index , int n , int k , vector<vector<int>>&output ,
 vector<int>&ans){

    if( ans.size() == k ){
       output.push_back(ans);
       return;
    }

   

    for(int i = index ; i <= n ; i++){
     ans.push_back(i);
     helper(i+1 , n , k , output , ans);
     ans.pop_back();

    }

}
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>>output;
        vector<int>ans;
        helper(1 , n , k , output , ans);
        return output;

    }
};