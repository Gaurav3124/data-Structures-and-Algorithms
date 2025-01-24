package Templates;
import static java.lang.Math.min;
import static java.lang.Math.max;
import static java.lang.Math.abs;
import static java.lang.System.out;
import java.util.*;
import java.io.*;
import java.math.*;

@SuppressWarnings("unused")
class MacroTemplate {
    public static void main (String args[]) throws Exception {
        BufferedReader infile = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(infile.readLine());
        /*
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        */
        
        int T = Integer.parseInt(st.nextToken());
        StringBuilder sb = new StringBuilder();
        while(T-- > 0) {
            st = new StringTokenizer(infile.readLine());
            int N = Integer.parseInt(st.nextToken());
            int[] arr = readArr(N, infile, st);
        }
        //BufferedReader infile = new BufferedReader(new FileReader("input.txt"));
        //System.setOut(new PrintStream(new File("output.txt")));
    }

    public static int[] readArr (int N, BufferedReader infile, StringTokenizer st) throws Exception{
        int[] arr = new int[N];
        st = new StringTokenizer(infile.readLine());
        for(int i=0; i<N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        return arr;
    }

    public static void print (int[] arr) {
        //for debugging only
        for(int x: arr)
            out.print(x+" ");
        out.println();
    }

    public static boolean isPrime(long n) {
        if(n < 2) return false;
        if(n == 2 || n == 3) return true;
        if(n%2 == 0 || n%3 == 0) return false;
        long sqrtN = (long)Math.sqrt(n)+1;
        for(long i = 6L; i <= sqrtN; i += 6) {
            if(n%(i-1) == 0 || n%(i+1) == 0) return false;
        }
        return true;
    }

    public static void sort(int[] arr) {
        //because Arrays.sort() uses quicksort which is dumb
        //Collections.sort() uses merge sort
        ArrayList<Integer> ls = new ArrayList<Integer>();
        for(int x: arr) ls.add(x);
        Collections.sort(ls);
        for(int i=0; i < arr.length; i++) arr[i] = ls.get(i);
    }
}