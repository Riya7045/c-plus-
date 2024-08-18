class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i =0,j=0,k=0;
        vector<int>nums3(nums1.size()+nums2.size());
        while(i<nums1.size()&& j<nums2.size()){
            if(nums1[i]<nums2[j]){
                nums3[k]=nums1[i];
                k++;
                i++;
            }
            else{
                nums3[k]=nums2[j];
                k++;
                j++;
            }
        }
        while (i < nums1.size()) {
            nums3[k++] = nums1[i++];
        }

        // Add remaining elements from nums2
        while (j < nums2.size()) {
            nums3[k++] = nums2[j++];
        }
        int total = nums3.size();
        if(total%2==1){
            return nums3[total/2];
        }
        else{
            int middle1 = nums3[total/2-1];
            int middle2 = nums3[total/2];
            return (double(middle1)+double(middle2))/2.0;
        }
    }
};