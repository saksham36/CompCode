class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int low = 0, high = nums.size() - 1;
        int mid;
        // Find pivot
        while (low < high)
        {
            mid = low + (high - low) / 2;
            // cout<<"Low: "<<nums[low]<<" Mid: "<<nums[mid]<<" High: "<<nums[high]<<endl;
            if (nums[mid] < nums[high]) // Search left side
                high = mid;
            else
                low = mid + 1;
        }
        return nums[low];
    }
};