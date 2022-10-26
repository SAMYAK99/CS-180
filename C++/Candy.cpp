int candy(vector<int>& A) {
        
        int n = A.size();
    
        vector<int> ans(n, 1);

        for(int i=1;i<n;i++) {
            if(A[i]>A[i-1]) {       
                ans[i] = ans[i-1] + 1;
            }
        }

        for(int i=n-1;i>=1;i--) {

            if(A[i-1]>A[i]) {
                ans[i-1] = max(ans[i] + 1, ans[i-1]);
            }

        }

        int sum = 0;
        
    

        for(int i=0;i<n;i++) {
            sum += ans[i];
        }

        return sum;
    
        
    }
