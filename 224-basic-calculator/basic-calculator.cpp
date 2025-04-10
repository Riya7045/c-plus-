class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        int ans=0,number=0,sign=1;
        for(char &ch:s){
            if(isdigit(ch)){
                number=10*number+(ch-'0');
            } else if(ch=='+'){
                ans+=sign*number;
                number=0;
                sign=1;
            } else if(ch=='-'){
                ans+=sign*number;
                number=0;
                sign=-1;
            } else if(ch=='('){
                st.push(ans);
                st.push(sign);
                ans=0;
                number=0,sign=1;
            } else if(ch==')'){
                ans+=sign*number;
                number=0;
                int topSign=st.top(); st.pop();
                // Multiply Sign
                ans*=topSign;
                // Add Prev ans
                int top=st.top(); st.pop();
                ans+=top;
            }
        }
        ans+=sign*number;
        return ans;
    }
};