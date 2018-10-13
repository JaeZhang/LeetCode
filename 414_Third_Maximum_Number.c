#include <stdio.h>
#include <stdbool.h>

int thirdMax(int* nums, int numsSize) {
    int max = nums[0];
    int second = max;
    int third = max;
    bool second_flag = false;
    bool third_flag = false;
    
    for (int i = 1; i < numsSize; i ++) {
    	if (second_flag == false) {
    		if (max > nums[i]) {
    			second = nums[i];
    			second_flag = true;
    		} else if (max < nums[i]) {
    			second = max;
    			max = nums[i];
    			second_flag = true;
    		}
    		continue;

    	}

    	if (third_flag == false) {
    		if (nums[i] > max) {
    			third = second;
    			second = max;
    			max = nums[i];
    			third_flag = true;
    		} else if (nums[i] > second && nums[i] < max) {
    			third = second;
    			second = nums[i];
    			third_flag = true;
    		} else if (nums[i] < second) {
    			third = nums[i];
    			third_flag = true;
    		}
    		continue;
    	}

    	if (second_flag && third_flag) {
    		if (nums[i] > max) {
    			third = second;
    			second = max;
    			max = nums[i];
    			
    		} else if (nums[i] > second && nums[i] < max) {
    			third = second;
    			second = nums[i];
    			
    		} else if (nums[i] < second) {
    			third = nums[i];
    		}
    	}
    }

    if (third_flag)
    	return third;
    else if (second_flag)
    	return second;
    else
    	return max;


}

int main () {
	int a [2] = {1, 2};
	int third = thirdMax(a, 2);
	printf("main third = %d\n", third);

	return 0;

}








