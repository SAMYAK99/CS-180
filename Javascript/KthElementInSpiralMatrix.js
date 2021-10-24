<script>
 
    let R = 3;
    let C = 6;
     
    function spiralPrint(m, n, a, c)
    {
        let i, k = 0, l = 0;
        let count = 0;
 
        while (k < m && l < n) {
    
            for (i = l; i < n; ++i) {
                count++;
 
                if (count == c)
                    document.write(a[k][i] + " ");
            }
            k++;
 
            for (i = k; i < m; ++i) {
                count++;
 
                if (count == c)
                    document.write(a[i][n - 1] + " ");
            }
            n--;
 
            if (k < m) {
                for (i = n - 1; i >= l; --i) {
                    count++;
 
                    if (count == c)
                        document.write(a[m - 1][i] + " ");
                }
                m--;
            }
 
            if (l < n) {
                for (i = m - 1; i >= k; --i) {
                    count++;
 
                    if (count == c)
                        document.write(a[i][l] + " ");
                }
                l++;
            }
        }
    }
   
      let a = [ [ 1, 2, 3, 4, 5, 6 ],
             [ 7, 8, 9, 10, 11, 12 ],
             [ 13, 14, 15, 16, 17, 18 ] ],
        k = 17;
  
    spiralPrint(R, C, a, k);
     
</script>