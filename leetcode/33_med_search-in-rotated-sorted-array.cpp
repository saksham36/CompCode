class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int start = 0, end = nums.size() - 1;
        int mid;
        cout << nums.size() << endl;
        while (start <= end)
        {
            mid = start + (end - start) / 2;
            // cout<<"Start: "<<start<<" End: "<<end<<" Mid: "<<mid<<endl;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] >= nums[start])
            { // Non rotated array
                // cout<<"Non rotated array"<<endl;
                if (target >= nums[start] && target < nums[mid])
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
            else
            {
                // cout<<"Rotated array"<<endl;
                if (target <= nums[end] && target > nums[mid])
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};