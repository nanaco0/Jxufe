//6.1 五角数（209页）

package exercise03;

public class PentagonalNumber {
	
	public static void main(String[] args) {
		for (int i = 0; i<100; i++) {
			if(i%10 == 0 && i != 0) System.out.printf("\n");
			System.out.printf("%7d", getPentagonalNumber(i+1));
		}
	}
	
	public static int getPentagonalNumber (int n) {
		return n*(3*n-1)/2;
	}
}