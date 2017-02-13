import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BJ1193 {
	public static void main(String []args) throws NumberFormatException, IOException{
		int n = 1,level=2;
		int count,pointer;
		int a,b;
		
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int input = Integer.parseInt(in.readLine().trim());
		
		while(true){
			if(n>input){
				level--;
				pointer = n-1;
				break;
			}
			
			n+=(level-1);
			level++;
		}
		
		count =0;
		while(true){
			count++;
			a=level-count;
			b= count;
			if(pointer == input){
				break;
			}
			pointer--;
		}
		if(level%2 != 0){
		System.out.println(a+"/"+b);
		}else{
			System.out.println(b+"/"+a);
		}
		
	}
}
