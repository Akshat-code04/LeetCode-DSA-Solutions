class Solution {
public:
    bool ispossible(vector<int>& position, int m,int mid){
        int ballcount = 1;
        int lastplaceball = position[0];

        for(int i=0;i<position.size();i++){

            if(position[i] - lastplaceball >= mid){
                ballcount++;
                lastplaceball = position[i];

                if(ballcount >= m){
                    return true;
                }
            }
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {

        sort(position.begin(),position.end());
        int start = 0;
        int maxi = 0;

        for(int i=0;i<position.size();i++){
            maxi = max(maxi,position[i]);
        }
        int end = maxi;
        int ans = -1;

        while(start <= end){

            int mid = start + (end - start)/2;

            if(ispossible(position,m,mid)){
                start = mid + 1;
                ans = mid;
            }
            else{
                end = mid - 1;
            }
        }
        return ans;
    }
};