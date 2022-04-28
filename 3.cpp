// 无重复字符的最长子串

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, size_t> dic;
        int rlen = 0;
        int tmplen = 0;
        int spos = 0; // 子字符串起始位置
        for (int i=0; i<s.length(); i++) {
            if (dic.find(s[i]) == dic.end() || dic[s[i]] < spos) {
                dic[s[i]] = i;
                ++tmplen;
            } else {
                rlen = (tmplen > rlen ? tmplen : rlen);
                tmplen = i - dic[s[i]];
                spos = dic[s[i]];
                dic[s[i]] = i;
            }
        }
        rlen = (tmplen > rlen ? tmplen : rlen);

        return rlen;
    }
};

/*
执行用时：
12 ms
, 在所有 C++ 提交中击败了
78.03%
的用户
内存消耗：
8.3 MB
, 在所有 C++ 提交中击败了
55.87%
的用户
通过测试用例：
987 / 987
*/
