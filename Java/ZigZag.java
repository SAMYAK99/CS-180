class ZigZag {

	static void zigzagTraverse(int [][]a, int n, int m) {
		int row = 0, col = 0;
		boolean goingDown = true;
		while (!OutOfBound(row, col, n, m)) {
			System.out.println(a[row][col]);
			if (goingDown) {
				if (col == 0 || row == n - 1) {
					goingDown = false;
					if (row == n - 1)
						col++;
					else
						row++;
				} else {
					row++;
					col--;
				}
			} else {
				if (row == 0 || col == m - 1) {
					goingDown = true;
					if (col == m - 1)
						row++;
					else
						col++;
				} else {
					row--;
					col++;
				}
			}
		}
	}

	static boolean OutOfBound(int row, int col, int n, int m) {
		return row < 0 || row > n - 1 || col < 0 || col > m - 1;
	}

	public static void main(String[] args) {
		int n = 3, m = 3;
		int [][]a = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
		zigzagTraverse(a, n, m);

	}
}