class Solution {
public:
    bool ispossible(vector<int>& weights,int days,int mid){
        int dayscount = 1;
        int sumofweights = 0;

        for(int i = 0;i<weights.size();i++){
            if(sumofweights + weights[i] <= mid){
            sumofweights += weights[i];
            }
            else{
            dayscount++;
            if(dayscount > days || weights[i] > mid){
                return false;
            }
            sumofweights = weights[i];
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int start = 0;
        int sum = 0;
        int ans = -1;
        for(int i=0;i<weights.size();i++){
            sum += weights[i];
            if(weights[i] > start){
            start = weights[i];
            }
        }

        int end = sum;
        
        while(start <= end){
            int mid = start + (end-start)/2;

            if(ispossible(weights,days,mid)){
                ans = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return ans;
    }
};