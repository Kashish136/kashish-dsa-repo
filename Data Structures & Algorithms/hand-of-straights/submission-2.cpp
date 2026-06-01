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


            int mini = mpp.begin()->first;
            if(mpp[mini] > 0){

                for(int i = 0 ; i < groupSize ; i++){

                    if(mpp[mini+i] > 0){
                        mpp[mini+i]--;

                        if(mpp[mini+i] == 0){
                            mpp.erase(mini+i);
                        }
                    }
                    else{
                        return false ;
                    }
                }
            }
        }

        return false ;
    }
};
