import java.util.Arrays;

public class MinimumNumberOfJumps {

	//Approach 1:DP
	static int solver(int []arr,int n) {
		int []dp=new int[n];
		Arrays.fill(dp,Integer.MAX_VALUE);
		dp[0]=0;

		for(int i=0;i<n;i++) {
			for(int j=i-1;j>=0;j--) {
				if(j+arr[j]>=i)
					dp[i]=Math.min(dp[i],dp[j]+1);
			}
		}
		return dp[n-1];
	}

	//Approach 2: Greedy
	static int solver2(int []arr,int n) {

		if(arr.length==1)
			return 0;
		
		int jumps=1,maxReach=arr[0],steps=arr[0];

		for(int i=1;i<n;i++) {
			maxReach=Math.max(maxReach,i+arr[i]);
			steps--;
			if(steps==0) {
				jumps++;
				steps=maxReach-i;
			}
		}
		return jumps;
	}

	public static void main(String[] args) {
		int []arr={3,4,2,1,2,3,7,1,1,1,3};
		System.out.println(solver2(arr,arr.length));
	}
}

//Result: 4