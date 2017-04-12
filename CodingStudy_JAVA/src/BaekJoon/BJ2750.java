package BaekJoon;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BJ2750 {
	public static void main(String []args) throws NumberFormatException, IOException{
		//selection sort
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(in.readLine().trim());
		int []arr = new int[n];
		for(int i=0;i<n;i++){
			arr[i] = Integer.parseInt(in.readLine().trim());
		}
		int temp,indexOfMin;
		
		for(int i=0;i<n-1;i++){
			indexOfMin = i;
			for(int j=i+1;j<n;j++){
				if(arr[j]<arr[indexOfMin]){
					indexOfMin =j;
				}
			}
			temp=arr[indexOfMin];
			arr[indexOfMin] =arr[i];
			arr[i] =temp;
		}
		for(int i=0;i<n;i++){
		System.out.println(arr[i]);
		}
	}
}
