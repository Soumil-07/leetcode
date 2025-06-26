class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // horizontal approach
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            string target = strs[i];
            while (prefix.size() != 0)
            {
                if (target.rfind(prefix, 0) == 0)
                    break;
                prefix = prefix.substr(0, prefix.size() - 1);
            }

            if (prefix.size() == 0) return "";
        }

        return prefix;
    }
};