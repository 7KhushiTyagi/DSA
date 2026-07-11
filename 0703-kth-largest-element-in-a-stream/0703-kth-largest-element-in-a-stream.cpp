class KthLargest {
    int m;
    priority_queue<int, vector<int>, greater<int>> p; 
public:
    KthLargest(int k, vector<int>& nums) {
        m=k;

        for(int num:nums){
            p.push(num);
            if(p.size()>k){
                p.pop();
            }
        }
        
    }
    
    int add(int val) {
        p.push(val);
        if(p.size()>m){
                p.pop();
            }

        return p.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */