import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class BJ1157 {
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String s = in.readLine();
		int []result = new int[26];

		for(int i=0;i<s.length();i++){
			if(s.charAt(i) >='a'){
					result[s.charAt(i)-'a']++;
			}else{
					result[s.charAt(i)-'A']++;
			}
		}
		
		int max=0;
		int index=0;
		boolean check = true;
		
		for(int i=0;i<result.length;i++){
			if(max==result[i])
				check=false;
			if(max<result[i]){
				max = result[i];
				index = i;
				check = true;
			}
		}
		
		if(check){
			System.out.println((char)('A'+index));
		}else{
			System.out.println("?");
		}
	}
}
