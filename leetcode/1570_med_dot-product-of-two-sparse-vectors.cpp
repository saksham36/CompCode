class SparseVector {
private:
public:
    unordered_map<int, int> map;
    SparseVector(vector<int> &nums) {
        for(int i = 0; i< nums.size(); i++){
            map[i] = nums[i];
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int result = 0;
        for (auto const &pair: vec.map) {
            if(map.count(pair.first)){
                result += pair.second * map[pair.first];
            }
        }
        return result;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);