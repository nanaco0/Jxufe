package exercise06;

public class StackOfPrime {

	public static void main(String[] args) {
		StackOfIntegers stack = new StackOfIntegers(31);
		int[] array = new int[31];
		int k=0;
		for(int i=120;i>=2;i--) {
			for(int j=2;j<=Math.sqrt(i);j++) {
				if(i%j==0) {
					k=1;
					break;
				}
			}
			if(k==0) {
				System.out.print(i+" ");
				stack.push(i);
			}
			k=0;
		}
		System.out.println();
		for(int n=0; n<=29; n++) {
			array[n] = stack.pop();
		}
		for(int i=29; i>=0; i--) {
			System.out.print(array[i]+" ");
		}
	}
}

