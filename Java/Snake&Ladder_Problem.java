import java.util.LinkedList;
import java.util.Queue;

public class SnakesLadder {
	static class qentry {
		int v; // Vertex number
		int dist; 
	}

	static int getMinDiceThrows(int move[], int n)
	{
		int visited[] = new int[n];
		Queue<qentry> q = new LinkedList<>();
		qentry qe = new qentry();
		qe.v = 0;
		qe.dist = 0;

		visited[0] = 1;
		q.add(qe);
    
		while (!q.isEmpty()) {
			qe = q.remove();
			int v = qe.v;

			if (v == n - 1)
				break;

			for (int j = v + 1; j <= (v + 6) && j < n;
				++j) {
				if (visited[j] == 0) {
					qentry a = new qentry();
					a.dist = (qe.dist + 1);
					visited[j] = 1;
					if (move[j] != -1)
						a.v = move[j];
					else
						a.v = j;
					q.add(a);
				}
			}
		}

		return qe.dist;
	}

	public static void main(String[] args)
	{
		int N = 30;
		int moves[] = new int[N];
		for (int i = 0; i < N; i++)
			moves[i] = -1;

		// Ladders
		moves[2] = 21;
		moves[4] = 7;
		moves[10] = 25;
		moves[19] = 28;

		// Snakes
		moves[26] = 0;
		moves[20] = 8;
		moves[16] = 3;
		moves[18] = 6;

		System.out.println("Min Dice throws required is "
						+ getMinDiceThrows(moves, N));
	}
}
