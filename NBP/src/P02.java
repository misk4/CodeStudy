import java.util.Scanner;

public class P02 {
	private int count;
	
	public P02(){
		this.count = 0;
	}
	
	public void count(){
		
		int i,j;
		
		Scanner input = new Scanner(System.in);
		System.out.println("Enter the max number : ");
		int max = input.nextInt();
		
		System.out.println("Enter a digit to count (0~9) : ");
		int num = input.nextInt();
		int length = String.valueOf(max).length();

		
		for(i = 0; i < length -1 ; i++ ){
			count += Math.pow(10, (length -2));
		}
		
		if(num == 0 ){
			count-=1;
		}
		
		for(i = (int) Math.pow(10,length-1); i<= max; i++){
			for(j = 0 ; j < String.valueOf(i).length(); j++){
				

				if(((int)String.valueOf(i).charAt(j)-48) == num){
					count++;
				}
			}
		}
		
		System.out.println(num+" appears " + count + " times");
	}
	/*public static void main(String[] args) {
		// TODO Auto-generated method stub
		P02 p = new P02();
		p.count();
		

	}*/
	
	
}