class Solution {
public:

  int helper(string&s , string&t , int i , int j){

       if( j < 0){
         return 1;
       }

       if( i < 0){
        return 0 ;
       }


       if(s[i] == t[j]){
         return helper(s , t , i-1 , j-1) + helper( s , t , i-1 , j);
       }

       else{
         return helper(s , t , i-1 , j);
       }
  }
    int numDistinct(string s, string t) {

        int n = s.size();
        int m = t.size();
        

        return helper( s , t , n-1 , m-1);
    }
};
