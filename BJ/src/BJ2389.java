import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class BJ2389 {


	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(input.readLine().trim());
		int []dp = new int[n+2];
		Arrays.fill(dp, 2000);
		for(int i=0; i<=n;i++){
			if(i%5 ==0 || i%3==0)
				dp[i]=1;
		}
		if(n>5){
			for(int i=6;i<=n;i++){
				dp[i] = Math.min(dp[i-3], dp[i-5])+1;
			}
		}

		if(dp[n] >=2000){
			System.out.println(-1);
		}else{
			System.out.println(dp[n]);
		}

	}

}
