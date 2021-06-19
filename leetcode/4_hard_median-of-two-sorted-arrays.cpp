class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() == 0){
            int mid = nums1.size()/2;
            if(nums1.size()%2==0)
                return (double)(nums1[mid-1] + nums1[mid])/2;
            else
                return nums1[mid];
        }
        if(nums1.size() == 0){
            int mid = nums2.size()/2;
            if(nums2.size()%2==0)
                return (double)(nums2[mid-1] + nums2[mid])/2;
            else
                return nums2[mid];    
        }
        
        if(nums1.size() > nums2.size()){
            nums1.swap(nums2);
        }
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        int begin = 0;
        int end = n1;
        int i1, i2, min1, min2, max1, max2;
//         for(int i=0; i<n1; i++)
//             cout<<nums1[i]<< " ";
//         cout<<endl;
        
//         for(int i=0; i<n2; i++)
//             cout<<nums2[i]<< " ";
//         cout<<endl;
        
        while(begin <= end){
            // cout<<"begin: "<<begin<<" end: "<<end<<endl;
            i1 = (begin+end)/2;
            i2 = (n1+n2+1)/2 -i1;
            // cout<<"i1 = "<< i1 << " i2 = "<<i2<<endl;
            min1 = (i1==n1)? INT_MAX: nums1[i1];
            max1 = (i1==0)? INT_MIN: nums1[i1-1];
            min2 = (i2==n2)? INT_MAX: nums2[i2];
            max2 = (i2==0)? INT_MIN: nums2[i2-1];
            // cout<<"max1: "<< max1 <<" min2: "<< min2<<endl;
            // cout<<"max2: "<< max2 <<" min1: "<< min1<<endl;
            if(max1<=min2 && max2<=min1){
                if((n1+n2)%2==0)
                    return (double)(max(max1, max2)+ min(min1,min2))/2;
                else
                    return max(max1, max2);
            }
            else if(max1>min2)
                end = i1-1;
            else
                begin = i1+1;
        }
    // cout<<"begin: "<<begin<<" end: "<<end<<endl;
    return -1;
    }
   
};