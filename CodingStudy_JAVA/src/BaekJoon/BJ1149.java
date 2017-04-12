package BaekJoon;

import java.util.Scanner;

public class BJ1149 {

	private int [][]rgb;
	private int [][]dp;
	private int numOfHouse;
	
	public BJ1149(){
		this.rgb = new int[1000][3];
		this.dp = new int[1000][3];
	}
	
	public void initCost(){
		Scanner input = new Scanner(System.in);
		this.numOfHouse = input.nextInt();
		
		for(int i=0; i< numOfHouse;i++){
			this.dp[i][0] = -1;
			this.dp[i][1] = -1;
			this.dp[i][2] = -1;
		}
		for(int i = 0; i < numOfHouse;i++){
			this.rgb[i][0] = input.nextInt();
			this.rgb[i][1] = input.nextInt();
			this.rgb[i][2] = input.nextInt();
		}
		
		this.dp[0][0] = this.rgb[0][0];
		this.dp[0][1] = this.rgb[0][1];
		this.dp[0][2] = this.rgb[0][2];
		
		input.close();
		
	}
	
	public int getMin(){
		int result;
		
		for(int i =1;i<numOfHouse;i++){
			dp[i][0] = min(dp[i-1][1],dp[i-1][2]) + rgb[i][0];
			dp[i][1] = min(dp[i-1][0],dp[i-1][2]) + rgb[i][1];
			dp[i][2] = min(dp[i-1][1],dp[i-1][0]) + rgb[i][2];
		}
		
		result = min(min(dp[numOfHouse-1][0],dp[numOfHouse-1][1]),dp[numOfHouse-1][2]);
		
		
		
		return result;
	}
	
	public int min(int a, int b){
		if(a>=b){
			return b;
		}else{
			return a;
		}
	}
	
	public static void main(String []args){
		BJ1149 BJ1149 = new BJ1149();
		BJ1149.initCost();
		
		System.out.println(BJ1149.getMin());
	}
}
