package BaekJoon;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class BJ11654 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String s = in.readLine();
		int []result = new int[26];
		Arrays.fill(result, -1);
		
		for(int i=0;i<s.length();i++){
			if(result[s.charAt(i)-'a'] == -1){
				result[s.charAt(i)-'a'] = i;
			}
		}
		
		System.out.print(result[0]);
		for(int i=1;i<result.length;i++){
			System.out.print(" "+result[i]);
		}
	}

}
