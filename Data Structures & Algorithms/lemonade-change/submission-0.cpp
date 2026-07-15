class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        int five = 0;
        int ten = 0;
        int twenty = 0;
        for(int i = 0 ; i < bills.size() ; i++){
            int bill = bills[i];
            if(bill == 5){
                five++;
            }

            else if(bill == 10){
                ten++;
                if(five > 0){
                    five--;
                }
                else{
                    return false;
                }
            }

            else{
                if(ten > 0 && five > 0){
                    twenty++;
                    ten--;
                    five--
                }

                else if(five >= 3){
                    five--;
                    five--;
                    five--;
                    twenty++;
                }

                else{
                    return false;
                }
            }
        }

        return true ;
    }
};