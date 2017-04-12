package BaekJoon;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BJ2675 {

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(in.readLine().trim());
		
		while(n-->0){
			StringBuffer out = new StringBuffer();
			String []s = in.readLine().split(" ");
			for(int j=0;j<s[1].length();j++){
				for(int i=0;i<Integer.parseInt(s[0]);i++){
					out.append(s[1].charAt(j));
				}
			}
			System.out.println(out);
		}
	}

}
