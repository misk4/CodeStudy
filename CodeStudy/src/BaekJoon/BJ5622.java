package BaekJoon;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BJ5622 {
	public static void main(String []args) throws IOException{
		int []time = {3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10};
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String s = in.readLine();
		
		int result =0;
		for(int i =0;i<s.length();i++){
			result += time[s.charAt(i)-'A'];
		}
		
		System.out.println(result);
	}
}
