class Solution {
public:
    int longestSubsequence(string s, int k) {
        long long bitWeight = 1;
        int count = 0;
        long long sum = 0;

        for (int i = s.size() - 1; i >= 0; i--)
        {
            char ch = s[i];
            if (bitWeight > k) {
                // from here on, only '0's can be added
                // count how many zeros remain (i+1 characters: s[0..i])
                count += std::count(s.begin(), s.begin() + i + 1, '0');
                break;
            }
            
            if (ch == '0') {
                count++;
                bitWeight <<= 1;
            }
            else if (ch == '1' && (sum + bitWeight) <= k)
            {
                count++;
                sum += bitWeight;
                bitWeight <<= 1;
            }
        }

        return count;
    }
};