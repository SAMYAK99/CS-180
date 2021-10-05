public class LevenshteinDistance {

	// Time: O(n*m) | Space: O(n*m)
	static int solve(String str1, String str2) {
		int n = str1.length(), m = str2.length();

		int [][]dp = new int[n + 1][m + 1];

		for (int i = 1; i < n; i++) {
			dp[i][0] = i;
		}

		for (int j = 1; j < m; j++) {
			dp[0][j] = j;
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (str1.charAt(i - 1) != str2.charAt(j - 1)) {
					dp[i][j] = 1 + Math.min(dp[i - 1][j - 1], Math.min(dp[i - 1][j], dp[i][j - 1]));
				} else
					dp[i][j] = dp[i - 1][j - 1];
			}
		}
		return dp[n][m];
	}

	// Time: O(n*m) | Space: O(n)
	static int solve2(String str1, String str2) {
		if (str1.length() < str2.length()) {
			String temp = str1;
			str1 = str2;
			str2 = temp;
		}

		int n = str1.length(), m = str2.length();
		int []even = new int[m + 1];
		int []odd = new int[m + 1];

		for (int i = 1; i < n; i++)
			even[i] = i;

		for (int i = 1; i < n; i++) {
			int []curr = odd;
			int []prev = even;
			if (i % 2 == 0) {
				curr = odd;
				prev = even;
			} else {
				curr = even;
				prev = odd;
			}

			curr[0] = 1;

			for (int j = 1; j <= m; j++) {
				if (str1.charAt(i - 1) == str2.charAt(j - 1))
					curr[j] = prev[j - 1];
				else
					curr[j] = 1 + Math.min(prev[j - 1], Math.min(curr[j - 1], prev[j]));
			}
		}
		return (n % 2 == 0) ? even[m] : odd[m];
	}
	public static void main(String[] args) {
		String str1 = "abc", str2 = "yabd";
		System.out.println(solve2(str1, str2));
	}
}