void rotate(int* nums, int numsSize, int k) {
	k = k % numsSize;
    for (int i = 0; i < k; i ++) {
    	int temp = nums[numsSize - 1];
    	for (int j = numsSize - 1; j >= 1; j --)
    		nums[j] = nums[j-1];
    	nums[0] = temp;
    }
}