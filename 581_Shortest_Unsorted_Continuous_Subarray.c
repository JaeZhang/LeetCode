int findUnsortedSubarray(int* nums, int numsSize) {
   	int sub1 = -1;
   	bool flag1 = false;

   	int sub2 = -1;
   	bool flag2 = false;
   	for (int i = 0; i < numsSize; i ++) {
   		for(int j = i + 1; j < numsSize; j ++) {
   			if (nums[i] > nums[j]) {
   				sub1 = i;
   				flag1 = true;
   			}
   		}
   		if (flag1)
   			break;
   	}

   	for (int i = numsSize -1; i >= 0; i --) {
   		for (int j = i -1; j>= 0; j --) {
   			if (nums[i] < nums[j]) {
   				sub2 = i;
   				flag2 = true;
   			}
   		}
   		if (flag2)
   			break;
   	}

   	return flag1 ? sub2 - sub1 + 1 : 0;

}