bool hasGroupsSizeX(int* deck, int deckSize) {
	if (deckSize == 1)
		return false;
	int group[deckSize];
    memset(group, 0, sizeof(group));
    
    int min = 2;
    int i;

    
    for (i = 0; i < deckSize; i ++) {
    	group[deck[i]] += 1;
    }

    i  = 0;
    while (i < deckSize) {
    	if (group[i] % min) {
    		min ++;
    		i = 0;
    	}
        
    	i ++;
        if (min > deckSize)
            break;
    }

   	
    return i==deckSize;
}
