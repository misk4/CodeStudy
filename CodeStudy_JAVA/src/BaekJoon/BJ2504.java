package BaekJoon;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class BJ2504 {
	public static void main(String []args) throws IOException{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		char []input = in.readLine().toCharArray();
		char []stack = new char[40];
		int []output = new int [40];
		
		int index=0,result =0;
		
		
		for(int i=0;i<input.length;i++){
			if(input[i]=='('){
				stack[index++] =input[i];
			}else if(input[i]=='['){
				stack[index++] =input[i];
			}else if(input[i] == ')' && stack[index-1]=='('){
				if(output[index]==0) output[index] =1;
				output[index-1]+=output[index]*2;
				output[index] =0;
				index--;
			}else if(input[i] == ']' && stack[index-1]=='['){
				if(output[index]==0) output[index] =1;
				output[index-1]+=output[index]*3;
				output[index] =0;
				index--;
			}else{
				System.out.println(0);
				return;
			}
		}
		
		System.out.println(output[0]);
		return;
	}
}
