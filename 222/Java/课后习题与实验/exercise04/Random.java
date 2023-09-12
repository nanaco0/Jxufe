//7.13 随机数�?�择�?

package exercise04;

public class Random {

	public static void main(String[] args) {
		for(int i=0;i<3;i++) {
			for(int j=0;j<15;j++) {
				System.out.printf("%4d", getRandom(1,100,4,8,95,93));
			}
			System.out.println();
		}
	}

	public static int getRandom(int start, int end, int... numbers) {
		if(numbers.length==0) {
			System.out.println("No argument passed !");
			return start-1;//返回值比start小为�?
		}
		int result = (int)(Math.random()*(end-start)+start);
		for(int e : numbers) {
			if (e!=result) {
				return result;
			}
		}
		return start-1;//编译器希望加上这�?行�?��?�可能是想防止死循环
	}
}
