class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int leftSum=0;
        for(int i=0;i<k;i++){
            leftSum+=cardPoints[i];
        }

        int maxi=leftSum;
        int rightSum=0;

        for(int i=0;i<k;i++){
            rightSum+=cardPoints[n-i-1];
            leftSum-=cardPoints[k-i-1];

            maxi=max(maxi,rightSum+leftSum);
        }

        return maxi;
        
    }
};