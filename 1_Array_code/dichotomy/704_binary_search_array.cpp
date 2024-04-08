/*给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
示例 1: 输入: nums = [-1,0,3,5,9,12], target = 9 输出: 4 */

#include <iostream>
#include <vector>
using namespace std;


class searchSolution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int middle = 0 ;

        while (left <= right){
            middle = left + (right-left)/2;

            if(nums[middle] > target){
                right = middle - 1;
            }
            else if (nums[middle] < target){
                left = middle + 1;
            }
            else {
                return middle;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;

    searchSolution binary_search;
    int result = binary_search.search(nums, target);
    cout << result << endl; 
    return 0;
}


/*
#include <iostream>
#include <vector>

using namespace std;

//typedef int show_def_t;

typedef struct test{
	int index;
} show_struct_t;

//static int s_aaaaaa;

class Solution {
public:
	int result;

	int search(vector<int> nums, int target) {
		p_search(nums, target);
		
		return 0;
	}

private:
	int p_search(vector<int>& nums, int target) {
		
		if (nums.size() <= 0) {
			
			return -1;
		} else {
			int left = 0, right = nums.size() - 1, middle = 0;
			
			while (left <= right) {
				middle = left + (int) ((right - left) / 2);
				
				if (nums[middle] > target) {
					right = middle - 1; 
				} else if (nums[middle] < target) {
					left = middle + 1;
				} else {
					result = middle;
					return 0;
				}
			}
			
			
			return -1;
		}
		
		return 0;
	}
};

int main()
{
	vector<int> nums = {-1, 0, 3, 5, 9, 12};
	Solution num_search;

	int32_t target = 12;

	int func_result = num_search.search(nums, target);
	if (func_result !=  0) {
		// error
	}

	int search_result = num_search.result;
	
	cout << search_result << endl;
	
	//	show_struct_t show_test;

	return 0;
}
*/