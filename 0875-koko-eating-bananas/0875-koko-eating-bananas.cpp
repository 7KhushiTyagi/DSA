class Solution {
    bool possible(int k,int h,vector<int> piles){
        long long hrs=0;

        for(int i=0;i<piles.size();i++){
            hrs+= (piles[i]+k-1)/k;
            if(hrs>h) return false;
        }
        return true;

    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());

        while(low<=high){
            int mid = low+(high-low)/2;

            if(possible(mid,h,piles)){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
        
    }
};