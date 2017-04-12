package BaekJoon;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class BJ1003 {

	List<Integer> fiboList;
	int zero,one;
	
	public BJ1003(){
		setToZero();
		fiboList = new ArrayList<Integer>();
	}
	
	
	public int fibo(int num){
		
		/*if(num ==0 ){
			zero++;
			return 0;
		}if(num == 1 ){
			one++;
			return 1;
		}if(fiboList.get(num) != -1){
			return fiboList.get(num);
		}
		
		fiboList.set(num,(fibo(num-1)+fibo(num-2)));
	
		
		
		return fiboList.get(num);*/
		
		if(num==0){
			zero++;
			return 0;
		}else if(num==1){
			one++;
			return 1;
		}else{
			return fibo(num-1)+fibo(num-2);
		}
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
		BJ1003 fibo = new BJ1003();
		Scanner input = new Scanner(System.in);
		int count = input.nextInt();//Integer.parseInt(input.nextLine());
		int num =0;
		
		while(count > 0){
			num = input.nextInt();
			
			fibo.setArray(num);
			fibo.fibo(num);
			fibo.printResult();
			fibo.setToZero();
			
			count --;
		}
		
		input.close();
	}
}
