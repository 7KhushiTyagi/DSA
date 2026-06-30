class Solution {
public:
bool possible(int day,int k,int m,vector<int> arr){
    int bouquet=0;
    int count=0;

    for(int i=0;i<arr.size();i++){
        if(arr[i]<=day){
            count++;
            if(count==k){
                bouquet++;
                count=0;
                if(bouquet==m) return true;
            }
        }else{
            count=0;
        }
    }
    return false;


}
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > bloomDay.size()) {
            return -1;
        }
        int low= *min_element(bloomDay.begin(),bloomDay.end());
        int high= *max_element(bloomDay.begin(),bloomDay.end());

        while(low<=high){
            int mid= low+(high-low)/2;

            if(possible(mid,k,m,bloomDay)){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};