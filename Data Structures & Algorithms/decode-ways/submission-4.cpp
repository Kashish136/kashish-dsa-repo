class Solution {
public:

   int helper(string s , int index){

       if(index == s.size()){
         return 1 ;
       }


       int result1 = 0;

       result1 = helper(s , index+1);

       int result2 = 0;

       if(index < s.size()-1){
         
         if(s[index] == '1'  || (s[index] == '2' && s[index+1] < '7')){
            result2 += helper(s , index+2)
         }
       }

     return (result1 + result2);
   }
    int numDecodings(string s) {
        
        return helper(s,0);
    }
};
