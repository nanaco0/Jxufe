package exercise05;

import java.util.Date;

public class TestDate {	
	
	public static void main(String[] args) {
		
		for(int i=4; i<=11; i++) {
			int j = (int) Math.pow(10, i);
			Date D = new Date(j);
			System.out.println(D.toString());
		}

	}

}
