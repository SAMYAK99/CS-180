import java.io.*;
import java.util.*;

public class PermutationsSwaps {

	static List<List<Integer>> graph;

	static List<List<Integer>> getComponents() {
		boolean []visited = new boolean[graph.size()];
		List<List<Integer>> list = new ArrayList<>();

		for (int i = 1; i < graph.size(); i++) {
			List<Integer> component = new ArrayList<>();
			if (!visited[i])
				dfs(i, component, visited);
			list.add(component);
		}

		return list;
	}

	static void dfs(int v, List<Integer> component, boolean []visited) {
		visited[v] = true;
		component.add(v);

		for (int i = 0; i < graph.get(v).size(); i++) {
			int curr = graph.get(v).get(i);
			if (!visited[curr])
				dfs(curr, component, visited);
		}
	}


	public static void main(String[] args)throws IOException {

		InputReader in = new InputReader();
		PrintWriter pw = new PrintWriter(System.out);
		int t = in.nextInt();
		outer: while (t-- > 0)  {
			int n = in.nextInt();
			int m = in.nextInt();
			int []p = in.readArray(n);
			int []q = in.readArray(n);
			int [][]edges = in.read2dArray(m, 2);

			graph = new ArrayList<>();

			for (int i = 0; i <= n; i++)
				graph.add(new ArrayList<>());

			for (int []edge : edges) {
				graph.get(edge[0]).add(edge[1]);
				graph.get(edge[1]).add(edge[0]);
			}

			List<List<Integer>> components = getComponents();

			for (List<Integer>  comp : components) {
				Set<Integer> set1 = new HashSet<>();
				Set<Integer> set2 = new HashSet<>();
				for (int v : comp) {
					set1.add(p[v - 1]);
					set2.add(q[v - 1]);
				}

				for (int i : set1)
					if (!set2.contains(i)) {
						pw.println("NO");
						continue outer;
					}
			}
			pw.println("YES");
		}

		pw.close();
	}

	static final Random random = new Random();

	static void ruffleSort(int[] a) {
		int n = a.length;
		for (int i = 0; i < n; i++) {
			int oi = random.nextInt(n), temp = a[oi];
			a[oi] = a[i];
			a[i] = temp;
		}
		ArrayList<Integer> lst = new ArrayList<>();
		for (int i : a)
			lst.add(i);
		Collections.sort(lst);
		for (int i = 0; i < n; i++)
			a[i] = lst.get(i);
	}

	static class InputReader {
		BufferedReader br;
		StringTokenizer st;

		public InputReader() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}
		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}
		int nextInt() {
			return Integer.parseInt(next());
		}
		long nextLong() {
			return Long.parseLong(next());
		}
		double nextDouble() {
			return Double.parseDouble(next());
		}
		int[] readArray(int n) {
			int []a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}
		long[] readLongArray(int n) {
			long []a = new long[n];
			for (int i = 0; i < n; i++)
				a[i] = nextLong();
			return a;
		}
		int [][] read2dArray(int n, int m) {
			int [][]a = new int[n][m];
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					a[i][j] = nextInt();
			return a;
		}
		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
	}
}