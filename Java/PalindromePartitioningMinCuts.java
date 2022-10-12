import java.util.Arrays;

public class PalindromePartitioningMinCuts {


	//Apprach 1: Naive solution O(n^3) time | O(n^2) space
	//Approach 2: Optimize isPalindrome check. Reduced time complexity: O(n^2) time

	static int solver(String str,int n) {
		boolean [][]dp=new boolean[n][n];

		//Approach 1: Normal function call to build dp array

		for(int i=0;i<n;i++) {
			for(int j=i;j<n;j++) {
				dp[i][j]=isPalindrome(str,i,j);
			}
		}

		// Approach 2: Optimized palindrome check

		dp=new boolean[n][n];

		for(int i=0;i<n;i++)
			dp[i][i]=true;

		for(int len=2;len<=n;len++) {
			for(int idx=0;idx<=n-len;idx++) {
				int end=idx+len-1;
				if(len==2)
					dp[idx][end]=str.charAt(idx)==str.charAt(end);
				else
					dp[idx][end]=str.charAt(idx)==str.charAt(end) && dp[idx+1][end-1];
			}
		}


		int[] cuts=new int[n];
		Arrays.fill(cuts,Integer.MAX_VALUE-1);

		for(int i=0;i<n;i++) {
			if(!dp[0][i]) {
				cuts[i]=cuts[i-1]+1;
				for(int j=1;j<i;j++)
					if(dp[j][i])
						cuts[i]=Math.min(cuts[i],cuts[j-1]+1);
			}
			else
				cuts[i]=0;
		}

		return cuts[n-1];
	}

	static boolean isPalindrome(String s,int i,int j) {
		while(i<j) {
			if(s.charAt(i)!=s.charAt(j))
				return false;
			i++; j--;
		}
		return true;
	}

	public static void main(String[] args) {
		String str="noonabbad";
		//use min cuts to make every part of string palindrome
		System.out.println("Min Cuts: "+solver(str,str.length()));
	}
}