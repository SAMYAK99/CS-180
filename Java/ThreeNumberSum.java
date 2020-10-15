import java.util.Arrays;

class ThreeNumberSum {

	// **** sort Array first -> o(n^2) approach ****
	public static void main(String[] args) {
		int n = 5;
		int k = 9;
		int []a = {1, 3, 5, 3, 2};
		int c = 0;
		Arrays.sort(a);
		for (int i = 0; i < n - 1; i++) {
			int l = i + 1, r = n - 1;
			while (l < r) {
				if (a[i] + a[l] + a[r] == k) {
					++c;
					System.out.println(a[i] + " " + a[l] + " " + a[r]);
					++l;
					r--;
				} else if (a[i] + a[l] + a[r] > k)
					r--;
				else if (a[i] + a[l] + a[r] < k)
					l++;
			}
		}
		if (c == 0)
			System.out.println("Not present");
	}
}