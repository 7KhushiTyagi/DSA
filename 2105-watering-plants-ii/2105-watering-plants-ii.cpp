class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int n=plants.size();
        int left=0;
        int right=n-1;
        int count=0;
        int a=capacityA;
        int b=capacityB;

        while(left<right){
            if(plants[left]>capacityA){
                capacityA=a;
                count++;
            }
            capacityA-=plants[left];
            left++;

            if(plants[right]>capacityB){
                capacityB=b;
                count++;
            }
            capacityB-=plants[right];
            right--;
        }

        if(left==right){
            if(max(capacityA,capacityB)<plants[left]){
                count++;
            }
        }

        return count;
        
    }
};