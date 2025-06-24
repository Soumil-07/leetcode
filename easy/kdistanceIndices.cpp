// https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        deque<int> keyPositions;
        vector<int> ret;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == key)
                keyPositions.push_back(i);
        }

        // start with the first key index
        int currIndex = keyPositions.front();
        keyPositions.pop_front();

        for (int i = 0; i < nums.size(); i++) {
            int indexDist = abs(currIndex - i);
            if (indexDist <= k)
            {
                ret.push_back(i);
            } else if (i > currIndex) {
                // out of the "boundary" of the first key
                if (keyPositions.empty()) break;

                currIndex = keyPositions.front();
                keyPositions.pop_front();
                indexDist = abs(currIndex - i);
                if (indexDist <= k)
                    ret.push_back(i);
            }
        }
        return ret;
    }
};
