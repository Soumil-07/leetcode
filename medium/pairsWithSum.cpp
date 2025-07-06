class FindSumPairs {
private:
    std::vector<int> _nums1;
    std::vector<int> _nums2;
    unordered_map<int, int> _nums2Freq;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        _nums1 = nums1;
        _nums2 = nums2;

        for (auto x : _nums2) {
            _nums2Freq[x] += 1;
        }
    }
    
    void add(int index, int val) {
        auto prevNum = _nums2[index];
        _nums2Freq[prevNum]--;
        _nums2[index] += val;
        _nums2Freq[prevNum + val]++;
    }
    
    int count(int tot) {
        int cnt = 0;
        for (auto x1 : _nums1) {
            if (x1 <= tot) cnt += _nums2Freq[tot - x1];
        }

        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */