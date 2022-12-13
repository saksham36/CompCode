class RandomizedSet {
private:
    unordered_map<int, int> dict;
    vector<int> idx_list;

public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(dict.count(val) == 0){ // val is not present
            idx_list.push_back(val);
            dict[val] = idx_list.size()-1;
            return true;
        }
        else
            return false;
    }
    
    bool remove(int val) {
        if(dict.count(val) == 0) // val is not present
            return false;
        else{
            // copy last element to place idx of element, then pop last
            idx_list[dict[val]] = idx_list.back();
            dict[idx_list.back()] = dict[val];
            idx_list.pop_back();
            dict.erase(val);
            return true; 
        }
    }
    
    int getRandom() {
        // rand() function gives random value in the range of 0 to RAND_MAX(whose value is 32767)
        return idx_list[rand()%idx_list.size()];
    }
    
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */