package CodeGround;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class CG_Intervals {

	public static void main(String []args) throws Exception{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		
		int T;
		int test_case;

		T = Integer.parseInt(in.readLine().trim());
		
		for(test_case = 1; test_case <= T; test_case++) {
			// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
			int n = Integer.parseInt(in.readLine().trim());
			
			//int [][]d = new int[n+1][n+1];
			int [][]bound = new int[n+1][2];
			int max = 1;
			
			for(int i=0;i<n;i++){
				String []line = in.readLine().split(" ");
				bound[i][0] = Integer.parseInt(line[0]);
				bound[i][1] = Integer.parseInt(line[1]);
				
			}
			
			for(int i=0;i<n;i++){
				int check =1;
				for(int j=0;j<n;j++){
					if(i==j)continue;
					if(bound[i][0]<bound[j][0]){
						if(bound[i][1]>bound[j][1]){
							check++;
						}
					}
				}
				if(check>max){
					max = check;
				}
			}
        
        

			// 이 부분에서 정답을 출력하십시오.
			System.out.println("Case #" + test_case);
			System.out.println(max);
			
		}
	}
}
