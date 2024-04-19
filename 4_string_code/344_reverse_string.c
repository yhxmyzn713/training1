/*
编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。
不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。

示例 1：
输入：s = ["h","e","l","l","o"]
输出：["o","l","l","e","h"]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char* a, char* b){
    char t = *a;
    *a = *b , *b = t;
}

void reverseString(char* s, int sSize) {
    for (int i =0,j=sSize-1; i<j;i++,j--){
        swap(s+i,s+j);
        
    }
    
}

int main(){
    char s[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    reverseString(s, strlen(s));
    printf("%s",s);
    return 0;

}