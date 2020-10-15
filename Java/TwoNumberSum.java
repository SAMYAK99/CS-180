import java.util.Arrays;
import java.util.HashSet;

class TwoNumberSum {

	// **** Approach 2 ****
	static void solve2(int []a, int n, int k) {
		int i = 0, j = n - 1, c = 0;
		Arrays.sort(a);
		while (i < j) {
			if (a[i] + a[j] == k) {
				++c;
				System.out.println(a[i] + " " + a[j]);
				i++;
				j--;
			} else if (a[i] + a[j] < k)
				i++;
			else if (a[i] + a[j] > k)
				j--;
		}
		if (c == 0)
			System.out.println("Not present");
	}

	// **** Approach 1 ****
	static void solve(int []a, int n, int k) {
		HashSet<Integer> h = new HashSet<>();
		Arrays.sort(a);
		int c = 0;
		for (int i = 0; i < n; i++) {
			if (h.contains(k - a[i])) {
				++c;
				System.out.println(a[i] + " " + (k - a[i]));
			} else
				h.add(a[i]);
		}
		if (c == 0)
			System.out.println("Not present");
	}

	public static void main(String[] args) {
		int n = 5;
		int k = 5;
		int []a = {2, 3, 4, 5, 1};
		solve(a, n, k);
	}
}
