import java.util.ArrayList;
import java.util.Scanner;

public class P03 extends Thread{
	
	private static int numOfString;
	private static int index;
	private static ArrayList<String> hayStack;
	private static ArrayList<Integer> indexOfItem;
	private static String needle;
	
	private int threadNum;
	
	public P03(int threadNum, ArrayList<String> hayStack,String needle){
		this.threadNum = threadNum;
		this.indexOfItem = new ArrayList<Integer>();
		this.hayStack = hayStack;
		this.needle = needle;
		this.index = 0;
		this.numOfString = hayStack.size();
	}
	
	
	private static synchronized int getIndex(){
		return index++;
	}
	
	private static synchronized void addIndex(int index){
		System.out.println();
		indexOfItem.add(index);
	}
	
	
	public ArrayList<Integer> getResult(){
		return indexOfItem;
	}
	
	public void run(){
		int tempIndex;
		float startTime =  System.currentTimeMillis();
		while(true){
			tempIndex = getIndex();
			if(tempIndex > numOfString-1){
				break;
			}
			//System.out.println(tempIndex);
			if(hayStack.get(tempIndex).equals(needle)){
				addIndex(tempIndex);
			}
			
		}
		float endTime =  System.currentTimeMillis();
		float time = endTime - startTime;
		System.out.println("D-thread-"+threadNum+" execution time : "+ time + "ms");
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		//다이나믹 쓰레드를 통한 needle 찾기 프로그램
		
		ArrayList<String> hayStack = new ArrayList<String>();
		Scanner input = new Scanner("find something in a needle stack\nwhere can i find a needle\nget me a needle\nfind something in a needle stack\nwhere can i find a needle\nget me a needle\nfind something in a needle stack\nwhere can i find a needle\nget me a needle\nfind something in a needle stack\nwhere can i find a needle\nget me a needle\nfind something in a needle stack\nwhere can i find a needle\nget me a needle");		//아주 긴 문자열 인풋
		
		while(input.hasNext()){
			String []temp = input.nextLine().split(" ");
			for(int i = 0; i< temp.length;i++){
				hayStack.add(temp[i]);
			}
		}
		
		int NUM_OF_THREAD = 4;		//쓰레드 개수
		String needle = "needle";
		
		P03 []dynamicThread = new P03[NUM_OF_THREAD];
		
		for(int i =0; i< NUM_OF_THREAD; i++){
			dynamicThread[i] = new P03(i,hayStack,needle);
		}
		
		
		for(int i = 0; i<NUM_OF_THREAD; i++){
			dynamicThread[i].start();
		}
		
		for(int i =0;i<NUM_OF_THREAD; i++){
			try{
				dynamicThread[i].join();
			}catch(InterruptedException e){
				e.printStackTrace();
			}
		}
		
		ArrayList<Integer> result =  dynamicThread[0].getResult();
		System.out.println("Number of needles found is "+result.size());
		for(int i = 0;i<result.size();i++){
			System.out.println("Index "+result.get(i)+" has a needle");
		}

	}

}
