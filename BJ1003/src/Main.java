import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {

	List<Integer> fiboList;
	int zero,one;
	
	public Main(){
		setToZero();
		fiboList = new ArrayList<Integer>();
	}
	
	
	public int fibo(int num){
		if(num ==0 ){
			zero++;
			return 0;
		}if(num == 1 ){
			one++;
			return 1;
		}if(fiboList.get(num) != -1){
			return fiboList.get(num);
		}
		
		fiboList.set(num,(fibo(num-1)+fibo(num-2)));
	
		
		
		return fiboList.get(num);
	}
	
	public void setToZero(){
		this.zero = 0;
		this.one = 0;
		fiboList = new ArrayList<Integer>();
	}
	
	public void printResult(){
		System.out.println(zero + " " + one);
	}
	
	public void setArray(int n){
		
		for(int i=0;i<n+1;i++){
			fiboList.add(-1);
		}

	}
	
	public static void main(String []args){
		Main fibo = new Main();
		Scanner input = new Scanner(System.in);
		int count = input.nextInt();//Integer.parseInt(input.nextLine());
		int num =0;
		
		while(count > 0){
			num = input.nextInt();
			System.out.println(num);
			fibo.setArray(num);
			System.out.println(fibo.fibo(num));
			fibo.printResult();
			fibo.setToZero();
			
			count --;
		}
		
		input.close();
	}
}
