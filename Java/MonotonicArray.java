class MonotonicArray {

	// *****Approach 1*****
	static boolean breaksDirection(int direction, int curr, int next) {
		int diff = next - curr;
		if (direction > 0)
			return diff < 0;
		else
			return diff > 0;
	}

	static boolean isMonotonic1(int []a, int n) {
		if (n == 2)
			return true;
		int direction = a[1] - a[0];
		for (int i = 2; i < n - 1; i++) {
			if (direction == 0) {
				direction = a[i + 1] - a[i];
				continue;
			}
			if (breaksDirection(direction, a[i], a[i + 1]))
				return false;
		}
		return true;
	}

	//  ***** Approach 2*****
	static boolean isMonotonic2(int []a, int n) {
		if (n == 2)
			return true;

		boolean isInc = true, isDec = true;
		for (int i = 0; i < n - 1; i++) {
			if (a[i] < a[i + 1]) {
				isDec = false;
			} else if (a[i] > a[i + 1]) {
				isInc = false;
			}
		}
		return isDec || isInc;

	}


	public static void main(String[] args) {
		int n = 5;
		int []arr = {2, 3, 4, 4, 5};
		System.out.println(isMonotonic1(arr, n));

	}
}