class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j=0;
        int n = nums1.size();
        int m = nums2.size();
        vector<int> vect;
        while(i<n && j < m){
            if(nums1[i]> nums2[j])
                j++;
            else if(nums1[i] < nums2[j])
                i++;
            else{
                if(vect.size() ==0 || nums1[i]!= vect.back())
                    vect.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        return vect;
    }
};
