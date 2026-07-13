class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int read=0;
        int write=0;

        while(read<n){
            char curr= chars[read];
            int count=0;

            while(read<n && chars[read]==curr){
                read++;
                count++;
            }

            chars[write++]=curr;

            if(count>1){
                string str= to_string(count);
                for(char c:str){
                    chars[write++]=c;
                }
            }
        }
        return write;
        
    }
};