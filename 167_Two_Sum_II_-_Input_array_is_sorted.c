/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int* res = (int*) malloc (2 * sizeof(int));
    *returnSize = 2;
    int i;
    for (i = 0; i < numbersSize; i ++) {
    	int search = target - numbers[i];
    	int two = find(numbers, search, i + 1, numbersSize - 1);
    	if (two != -1) {
    		res[0] = i + 1;
    		res[1] = two + 1;
            break;
    	} 

    }

    return res;

}

int find(int* numbers, int target, int left, int right) {
	int mid;
	bool flag = false;
	while(left <= right) {
		mid = (left + right) / 2;
		if (numbers[mid] == target) {
			flag = true;
			break;
		} else if (target < numbers[mid]) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}

	return flag ? mid : -1;
}