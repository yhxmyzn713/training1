/*
给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"
解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

char* minWindow(char* s, char* t) {
    int map[256] = { 0 };   //用 map[] 统计字符串 t 中各字母的个数
    int subLength = 0, result = INT_MAX;
    int start = 0;
    int sLen = strlen(s), tLen = strlen(t); //用 tLen 统计还未找到的字符串 t 中字母的个数
    for (int i = 0; i < tLen; i++) {    //统计字符串 t 中各字母的个数
        map[t[i]]++;
    }
    for (int left = 0, right = 0; right < sLen; right++) {
        if (map[s[right]]-- > 0) {  //s 中每个字母的对应的哈希表 -1
            tLen--; //若是对应字符串 t 的字母，则更新tLen的值
        }
        while (tLen == 0) {     //出现匹配的子串
            subLength = right - left + 1;
            if (subLength < result) {   //更新最小匹配子串的起点 start 和长度 result
                start = left;
                result = subLength;
            }
            if (++map[s[left]] > 0) {   //更新窗口数据：map[] 和 tLen
                tLen++;
            }
            left++;     //窗口左端left右移一位
        }
    }
    if (result != INT_MAX) {  //找到了最小匹配字串
        char* res = (char*)malloc(sizeof(char) * (result + 1));
        *res = '\0';
        strncat(res, s + start, result);
        return res;
    }
    return "";  //没有找到最小匹配字串
}

int main() {
    char* s = "ADOBECODEBANC";
    char* t = "ABC";
    char* result = minWindow(s, t);
    printf("%s\n", result);
}