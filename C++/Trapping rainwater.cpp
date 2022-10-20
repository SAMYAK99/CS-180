int volumeOfTrappedRainWater(vector<int> &heights) {
    int n = heights.size();
	int totalRainWater = 0;
	for (int i = 0; i < n; i++){
		int maxLeft = 0, maxRight = 0;
		for (int j = 0; j <= i; j++){
			maxLeft = max (maxLeft, heights[j]);
		}
		for (int j = i; j < n; j++) {
			maxRight = max (maxRight, heights[j]);
		}
		totalRainWater += min (maxRight, maxLeft) - heights[i];
	}
	return totalRainWater;
}
