package term;

public class Test{
	  public static void main (String[] args){
			A a = new B();
			double renkou=1400000;
			for(int i=0;i<10;i++) {
				renkou*=97;
				System.out.println(renkou);
			}
			

		}
	}

	class A {
		int m(double x) {
			return (int) x;
		}
	}
	class B extends A{
		double m(int x) {
			return x;
		}
		int m(double x) {
			return (int) x * 2;
		} 
	} 
