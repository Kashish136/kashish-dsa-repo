class Solution {
public:

   void helper(vector<string>&ans , string&str , int n , int open , int close){
         
        if(open == n && close == n ){
            ans.push_back(str);
            return ;
        }

        if(open < n){
            str.push_back('(');
            helper(ans , str , n , open+1 , close);
            str.pop_back();
        }

        if(close < open){
            str.push_back(')');
            helper(ans , str , n , open , close+1);
            str.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        

        vector<string>ans;
        string str ;

        helper(ans , str , n , 0 , 0 );
        return ans ;
    }
};
