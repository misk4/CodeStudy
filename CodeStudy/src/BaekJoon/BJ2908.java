package BaekJoon;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BJ2908 {
	
	public static int backwards(String s){
		StringBuffer buffer = new StringBuffer();
		for(int i=0;i<s.length();i++){
			buffer.insert(0, s.charAt(i));
		}
		
		return Integer.parseInt(buffer.toString());
	}
	
	public static void main(String []args) throws IOException{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer tok = new StringTokenizer(in.readLine());
		
		String a = tok.nextToken();
		String b = tok.nextToken();
		
		int aa = backwards(a);
		int bb = backwards(b);
		
		System.out.println(Math.max(aa, bb));
		
		
	}
}
