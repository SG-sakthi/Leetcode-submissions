class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totaltank =0;
        int currtank =0;
        int start =0;
        for(int i =0; i<gas.size(); i++){
            int profit = gas[i] - cost[i];
            totaltank +=profit;
            currtank +=profit;
            if(currtank<0){
                start = i+1;
                currtank =0;
            }
     }
     return(totaltank>=0) ?start :-1;
    }
};