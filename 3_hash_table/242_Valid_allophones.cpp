/*
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。



*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26] = {0};
        for (int i=0; i<s.size(); i++) {
        // 并不需要记住字符a的ASCII，只要求出⼀个相对数值就可以了
        record[s[i] -'a']++;
        }

        for (int i=0; i<t.size(); i++) {
            record[t[i] -'a']--;
          }
        for (int i=0; i<26; i++) {
            if (record[i] !=0) {
        // record数组如果有的元素不为零0，说明字符串s和t ⼀定是谁多了字符或者谁少了字符。
                return false;
            }
        }

    // record数组所有元素都为零0，说明字符串s和t是字⺟异位词
    return true;

    }
};


int main() {
    Solution sol;
    string s = "anagram";
    string t = "nagaram";

    // 测试用例
    bool result = sol.isAnagram(s, t);
    cout << (result ? "true" : "false") << endl; // 应输出 true

    // 你可以添加更多测试用例来验证不同情况：
    cout << (sol.isAnagram("rat", "car") ? "true" : "false") << endl; // 应输出 false
    cout << (sol.isAnagram("listen", "silent") ? "true" : "false") << endl; // 应输出 true

    return 0;
}