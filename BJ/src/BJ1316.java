import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class BJ1316 {
	public static void main(String []args) throws NumberFormatException, IOException{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(in.readLine().trim());
		int count =0;
		while(n-->0){
			String s = in.readLine();
			int []result = new int[26];
			Arrays.fill(result,-1);
			char temp='a';
			boolean check = true;

			for(int i=0;i<s.length();i++){
				if(result[s.charAt(i)-'a'] == -1){
					result[s.charAt(i)-'a']++;
					temp = s.charAt(i);
				}else if(temp ==s.charAt(i)){
					result[s.charAt(i)-'a']++;
				}else{
					check =false;
				}
			}
			
			if(check)
				count++;
		}
		
		System.out.println(count);
	}
}
