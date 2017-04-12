package CodeGround;
import java.io.BufferedReader;
import java.io.InputStreamReader;


public class CG_Marathon {
	
	static int [][]height;
	static int [][][]dp;
	static int x,y,w;
	static final int INF = 987654321;
	
	public static int min(int a, int b){
		if(a<=b){
			return a;
		}else{
			return b;
		}
	}
	
	public static int dis(int a, int b){
		return Math.abs(Math.abs(a)-Math.abs(b));
	}
	
	public static int findPath(int Y, int X, int k){
		if(Y==y && X==x ){
			if(k<=0){
				return 0;
			}else{
				return INF;
			}
		}
		if(k<=0)k=0;
		
		if(dp[Y][X][k] != -1) return dp[Y][X][k];
		dp[Y][X][k] =INF;
		
		
		if(Y<y){
			int tempK = k;
			if(height[Y+1][X]<0){
				tempK = k-1;
			}
			dp[Y][X][k] = findPath(Y+1,X,tempK)+dis(height[Y+1][X],height[Y][X]);
		}
		if(X<x){
			int tempK = k;
			if(height[Y][X+1]<0){
				tempK = k-1;
			}
			dp[Y][X][k] = min(dp[Y][X][k],findPath(Y,X+1,tempK)+dis(height[Y][X+1],height[Y][X]));
		}
		
		return dp[Y][X][k];
	}
		

	public static void main(String args[]) throws Exception	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		
		int T=Integer.parseInt(in.readLine().trim());
		int test_case;

		     
		for(test_case = 1; test_case <= T; test_case++) {
			
			String []str = in.readLine().split("\\s");
			x=Integer.parseInt(str[0]);
			y=Integer.parseInt(str[1]);
			w=Integer.parseInt(str[2]);
			
			height = new int[y+1][x+1];
			dp = new int [y+1][x+1][w+1];
			
			for(int i=0;i<=y;i++){
				str = in.readLine().split("\\s");
				for(int j=0;j<=x;j++){
					for(int k=0;k<=w;k++){
						dp[i][j][k] =-1;
					}
					height[i][j] = Integer.parseInt(str[j]);
 				}
			}
			
			System.out.println("Case #" + test_case+" "+findPath(0,0,w));
			
		}
	}

}
