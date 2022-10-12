import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
class TestClass {
    public static void main(String args[] ) throws Exception {
        Myscanner s=new Myscanner();
        int n=s.nextInt();
        String str=s.next();
        int max=0;
        for(int i='a';i<='z';i++){
            int count=0;
            for(int j=0;j<str.length();j++){
                if(i==str.charAt(j)){
                    count++;
                }
            }
            max=Math.max(count,max);
        }
System.out.println(max);
    }
 public static class Myscanner{
        private BufferedReader br;
        private StringTokenizer tr;
        public Myscanner(){
            br=new BufferedReader(new InputStreamReader(System.in));
         }
         public String next(){
             try{
                 while(tr==null||!tr.hasMoreTokens()){
                     tr=new StringTokenizer(br.readLine());
                 }
             }
             catch(Exception e){
                 e.printStackTrace();
             }
             return tr.nextToken();
         }
         public int nextInt(){
             return Integer.parseInt(next());
         }
         public long nextlong(){
             return Long.parseLong(next());
         }
    }
    }

