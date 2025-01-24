import static java.lang.Math.min;
import static java.lang.Math.max;
import static java.lang.Math.abs;
import static java.lang.System.out;
import java.util.*;
import java.io.*;
import java.math.*;

@SuppressWarnings("unused")
class C_Remove_Exactly_Two {
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
            int N = Integer.parseInt(infile.readLine());
            int [][] graph = new int[N][];
            while(N-- > 1) {
                st = new StringTokenizer(infile.readLine());
                graph[]
            }

        }


        //BufferedReader infile = new BufferedReader(new FileReader("input.txt"));
        //System.setOut(new PrintStream(new File("output.txt")));
    }

    public static int[] readArr (int N, BufferedReader infile, StringTokenizer st) throws Exception {
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

    public static void sort(int[] arr) {
        //because Arrays.sort() uses quicksort which is dumb
        //Collections.sort() uses merge sort
        ArrayList<Integer> ls = new ArrayList<Integer>();
        for(int x: arr) ls.add(x);
        Collections.sort(ls);
        for(int i=0; i < arr.length; i++) arr[i] = ls.get(i);
    }
}