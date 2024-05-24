class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        long long int revNum=0;
        int dup=x;
        while(x>0){
            int temp=x%10;
            revNum=(revNum*10)+temp;
            x=x/10;
        }
        if(dup==revNum){
            return true;
        }
        else{
            return false;
        }

        
    }
};