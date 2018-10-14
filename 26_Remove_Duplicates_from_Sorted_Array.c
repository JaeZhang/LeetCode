int removeDuplicates(int* nums, int numsSize) {
	if (!numsSize)
		return 0;
 	int temp = nums[0];
 	int count = 1;
 	for (int i = 1; i < numsSize; i ++) {
 		if (nums[i] != temp) {
 			nums[count++] = nums[i];
 			temp = nums[i];
 		}
 	}   
 	return count;
}