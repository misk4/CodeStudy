import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BJ2292 {
	public static void main(String []args) throws IOException{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int n  = Integer.parseInt(in.readLine().trim());
		
		int max =1;
		int level =1;
		int count=1;
		
		while(true){
			if(n<=max){
				break;
			}
			count++;
			max += 6*level;
			level++;
		}
		
		System.out.println(count);
		

	}
}
