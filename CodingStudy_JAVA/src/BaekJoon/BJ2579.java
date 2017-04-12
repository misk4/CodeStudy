package BaekJoon;

import java.util.Scanner;

//백준 2579
public class BJ2579 {
	
	public static void main(String []args){

		Scanner input = new Scanner(System.in);
		int numOfStairs = input.nextInt();
		int i = 1;
	
		int []dp = new int[numOfStairs+2];
		int []point = new int[numOfStairs+2];
		
		while(true){
			point[i-1] = input.nextInt();
			i++;
			if(i>numOfStairs){
				input.close();
				break;
			}
		}
		
		dp[0] = point[0];
		dp[1] = point[1]+point[0];
		dp[2] = max(dp[0]+point[2],point[1]+point[2]);	//35
		
		for(i=3;i<numOfStairs;i++){
			dp[i] = max(dp[i-3]+point[i-1]+point[i], dp[i-2]+point[i]);
		}
		
		System.out.println(dp[numOfStairs-1]);
		
	}
	
	public static int max(int a,int b){
		if(a>=b){
			return a;
		}else{
			return b;
		}
	}
	
}
