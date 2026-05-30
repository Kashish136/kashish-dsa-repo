class Solution {
public: 

    unordered_map<char , string>mpp =
    {{ '2' , "abc"} , {'3',"def"} , {'4' , "ghi"} , 
    {'5' , "jkl"} , {'6', "mno"} , {'7' , "pqrs"}, {'8' , "tuv"} ,
     {'9' , "wxyz"}};


    void helper(int index , string&digits , unordered_map<char,string>&mpp,
    vector<string>&answer , string&str){


        if(index == digits.size()){
            answer.push_back(str);
            return;
        }

        string st = mpp[digits[index]];

        for( char ch : st){
            str.push_back(ch);
            helper(index+1 , digits , mpp , answer , str);
            str.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        
        string str;
        vector<string>answer;
        helper(0 , digits , mpp, answer , str);
        return answer ;
    }
};
