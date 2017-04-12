package BaekJoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class BJ9012 {

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		Stack<Integer> stack = new Stack<Integer>();
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int testCase = Integer.parseInt(in.readLine().trim());
		while(testCase-->0){
			String s = in.readLine();
			stack.clear();
			boolean check = true;
			for(int i=0;i<s.length();i++){
				if(s.charAt(i)=='('){
					stack.push(0);
				}else{
					if(stack.isEmpty()){
						check = false;
						break;
					}
					stack.pop();
				}
			}
			if(stack.isEmpty() && check){
				System.out.println("YES");
			}
			else{
				System.out.println("NO");
			}
		}
	}

}
