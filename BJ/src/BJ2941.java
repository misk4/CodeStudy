import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class BJ2941 {
	public static void main(String []args) throws IOException{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String s = in.readLine();

		int count =0;
		for(int i=0;i<s.length();i++){
			count+=1;
			if(i<s.length()-1){
				if(s.substring(i, i+2).equals("c=")||s.substring(i, i+2).equals("c-")||s.substring(i, i+2).equals("d-")||s.substring(i, i+2).equals("lj")||s.substring(i, i+2).equals("nj")||s.substring(i, i+2).equals("s=")||s.substring(i, i+2).equals("z=")){
					i++;
				}}
			if(i<s.length()-2){
				if(s.substring(i, i+3).equals("dz=")){
					i+=2;
				}
			}
		}
		System.out.println(count);
	}
}
