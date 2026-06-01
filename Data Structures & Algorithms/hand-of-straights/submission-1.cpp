class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        

        sort(hand.begin() , hand.end());
        int n = hand.size();
        map<int,int>mpp;

        for(int i = 0 ; i < n ; i++){
            int value = hand[i];
            mpp[value]++;
        }

        // making the map for keeping the elements in sorted fashion 



        while(true){
            

            if(mpp.empty()){
                return true ;
            }


            int mini = *min_element(hand.begin() , hand.end());
            if(mpp[mini] > 0){

                for(int i = 0 ; i < 4 ; i++){

                    if(mpp[mini+i] > 0){
                        mpp[mini]--;

                        if(mpp[mini] == 0){
                            mpp.erase(mini);
                        }
                    }
                    else{
                        break;
                    }
                }
            }
        }

        return false ;
    }
};
