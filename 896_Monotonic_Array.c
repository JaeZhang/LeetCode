bool isMonotonic(int* A, int ASize) {
	if (ASize <= 1)
		return true;
    bool flag = (A[ASize-1] >= A[0]) ? true : false;
    int i = 1;
    if (flag) {
    	while (i <= ASize-1) {
    		if (A[i] < A[i-1]) {
    			return false;
    		}
    		i ++;

    	}
    } else {
    	while (i <= ASize-1) {
    		if (A[i] > A[i-1]) {
    			return false;
    		}
    		i ++;
    	}
    }
    return true;
}