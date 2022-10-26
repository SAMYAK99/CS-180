 int equilibriumPoint(long long a[], int n) {
        long long sum=0,sum_so_far=0;
        for(int i=0;i<n;i++)
        { sum +=a[i];
        }
        if(n==1)
        {
            return n ;
        }
        if(n==0)
        {
            return -1;
        }
        for(int i=0;i<n;i++)
        { sum=sum-a[i];
          if(sum==sum_so_far)
          {
              return i+1;
          }
          sum_so_far=sum_so_far+a[i];
        }
        return -1;
        
    }
