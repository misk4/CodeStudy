
public class GcpBehavior implements ServerBehavior {

	public int getCpuUsage(){
		int usage = 15;
		
		// API를 활용하여 1주일 간의 CPU 이용률 가져온다.
		// usage = apiGCP.getCpuUsage();
		
		return usage;
	}
}
