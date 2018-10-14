int searchInsert(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    int mid;

    while (left <= right) {
    	mid = (left + right) / 2;
    	if (target == nums[mid])
    		break;
    	if (target < nums[mid]) {
    		right = mid - 1;
    	}
    	if (target > nums[mid])
    		left = mid + 1;
    }
    return left <= right ? mid : left;
}