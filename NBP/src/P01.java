
public class P01 {

	private String name;
	private String type;
	
	private ServerBehavior serverBehavior;	//strategy pattern
	
	public P01(String name, String type){
		this.name = name;
		this.type = type;
		if(type.equals("AWS")){
			this.serverBehavior = (ServerBehavior) new AwsBehavior();
		}else if(type.equals("GCP")){
			this.serverBehavior = (ServerBehavior) new GcpBehavior();
		}else{
			this.serverBehavior = (ServerBehavior) new DefaultBehavior();
		}
	}
	
	public int getCpuUsage(){
		return this.serverBehavior.getCpuUsage();
	}
	
	public String getType(){
		return this.type;
	}
	
	public String getName(){
		return this.name;
	}
	
	/*public static void main(String[] args) {
		
		P01 []server = new P01[3];
		server[0] = new P01("aws server", "AWS");
		server[1] = new P01("gcp server", "GCP");
		server[2] = new P01("temp server", "temp");
		
		for(int i= 0; i<server.length;i++){
			if(server[i].getCpuUsage() < 10){
				System.out.println(server[i].getType() +" : "+ server[i].getName()+ " has cpu usage under 10% (" +server[i].getCpuUsage()+"%)");
			}
		}

	}*/

}
