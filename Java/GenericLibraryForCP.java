import java.io.*;
import java.io.InputStreamReader;
import java.util.*;

public class GenericLibraryForCP {

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(
                    new InputStreamReader(System.in));
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

        String nextLine() {
            String str = "";
            try {
                if (st.hasMoreTokens()) {
                    str = st.nextToken("\n");
                } else {
                    str = br.readLine();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    static void printArr(int[] arr) {
        for (int j : arr) {
            System.out.print(j + " ");
        }
        System.out.println();
    }

    static void printArrList(ArrayList<Integer> arr) {
        for (int j : arr) {
            System.out.print(j + " ");
        }
        System.out.println();
    }

    static class Pair {
        int first;
        int second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    static class Trio {
        String first;
        int second;
        int third;

        Trio(String first, int second, int third) {
            this.first = first;
            this.second = second;
            this.third = third;
        }
    }
    static class sortPairBySecond implements Comparator<Pair> {

        @Override
        public int compare(Pair o1, Pair o2) {

            return o1.second - o2.second;
        }
    }

    static class sortPairByFirst implements Comparator<Pair> {

        @Override
        public int compare(Pair o1, Pair o2) {
            return o1.first - o2.first;
        }
    }

    static class sortTrioByFirst implements Comparator<Trio> {

        @Override
        public int compare(Trio o1, Trio o2) {

            if (o1.first.compareTo(o2.first) == 0){
                return o1.third - o2.third;
            }

            else return o1.first.compareTo(o2.first);
        }
    }

    static class sortTrioBySecond implements Comparator<Trio> {

        @Override
        public int compare(Trio o1, Trio o2) {

            if (o1.second == o2.second){
                return o1.third - o2.third;
            }

            else return o1.second - o2.second;
        }
    }

    static class sortTrioByThird implements Comparator<Trio> {

        @Override
        public int compare(Trio o1, Trio o2) {

            return o1.third - o2.third;
        }
    }

    static long exponentMod(long A,
                            long B, long C)
    {

        // Base cases
        if (A == 0)
            return 0;
        if (B == 0)
            return 1;

        // If B is even
        long y;
        if (B % 2 == 0)
        {
            y = exponentMod(A, B / 2, C);
            y = (y * y) % C;
        }

        // If B is odd
        else
        {
            y = A % C;
            y = (y * exponentMod(A, B - 1,
                    C) % C) % C;
        }

        return ((y + C) % C);
    }

    static long nCr(long n, long r)
    {
        return fact(n) / (fact(r) *
                fact(n - r));
    }
    static long fact(long n)
    {
        if(n==0)
            return 1L;
        long res = 1L;
        for (long i = 2L; i <= n; i++)
            res = res * i;
        return res;
    }

    static class Graph
    {


        int V;

        Vector<Integer>[] adj;

        @SuppressWarnings("unchecked")
        Graph(int V)
        {
            adj = new Vector[V];
            for (int i = 0; i < adj.length; i++)
            {
                adj[i] = new Vector<>();
            }
            this.V = V;
        }

        void addEdge(int v, int w)
        {

            adj[v].add(w);

            adj[w].add(v);
        }

        int BFS(int s, int l)
        {

            boolean[] visited = new boolean[V];
            int[] level = new int[V];

            for (int i = 0; i < V; i++)
            {
                visited[i] = false;
                level[i] = 0;
            }

            Queue<Integer> queue = new LinkedList<>();

            visited[s] = true;
            queue.add(s);
            level[s] = 0;
            int count = 0;
            while (!queue.isEmpty())
            {

                s = queue.peek();
                queue.poll();

                Vector<Integer> list = adj[s];

                for (int i : list)
                {
                    if (!visited[i])
                    {
                        visited[i] = true;
                        level[i] = level[s] + 1;
                        queue.add(i);
                    }
                }

                count = 0;
                for (int i = 0; i < V; i++)
                    if (level[i] == l)
                        count++;
            }
            return count;
        }
    }

    static int nCrModp(int n, int r)
    {
        if (r > n - r)
            r = n - r;

        // The array C is going to store last
        // row of pascal triangle at the end.
        // And last entry of last row is nCr
        int C[] = new int[r + 1];

        C[0] = 1; // Top row of Pascal Triangle

        // One by constructs remaining rows of Pascal
        // Triangle from top to bottom
        for (int i = 1; i <= n; i++) {

            // Fill entries of current row using previous
            // row values
            for (int j = Math.min(i, r); j > 0; j--)

                // nCj = (n-1)Cj + (n-1)C(j-1);
                C[j] = (C[j] + C[j - 1]) % 998244353;
        }
        return C[r];
    }

    public static void main(String[] args) throws Exception {

        FastReader sc = new FastReader();

        int T = sc.nextInt();

        while (T>0){
            T--;



        }

    }

}