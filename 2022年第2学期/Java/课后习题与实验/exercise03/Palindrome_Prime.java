//6.26 回文素数�?215页）

package exercise03;

public class Palindrome_Prime {
	public static void main(String[] args) {
		getPalindrome_Prime(100);
	}
	
	public static void getPalindrome_Prime (int n) {
		int count = 0;
		for(int i=2; count < n; i++) {
			if(isPrime(i) & isPalindrome(i)) {
				System.out.printf("%d ", i);
				count++;
				if(count%10==0) System.out.printf("\n");
			}
		}
	}
	
	public static boolean isPalindrome (int x) {
		String str = String.valueOf(x);
		StringBuilder sb = new StringBuilder(str);
		sb.reverse();
		return sb.toString().equals(str);
	}
	
	public static boolean isPrime (int x) {
		int count=0;
		for(int i=2; i<=(int)Math.sqrt(x); i++) {
			if(x%i==0) count++;
		}
		if(count==0) return true;
		else return false;
	}
}