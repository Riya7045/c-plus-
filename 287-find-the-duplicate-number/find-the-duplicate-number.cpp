class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        int s =nums[0];
        int f =nums[0];
        //finding the intersection point in the cycle
        while(true){
            s = nums[s]; //move slow pointer by 1 step
            f = nums[nums[f]]; //move fast by 2 step
            if(s==f){
                break;
            }
        }
        //finding the entrance to the cycle
        int ptr1 = nums[0];
        int ptr2=s;
        while(ptr1!=ptr2){
            ptr1 = nums[ptr1];
            ptr2 = nums[ptr2];
        }
        return ptr1;
    }
};