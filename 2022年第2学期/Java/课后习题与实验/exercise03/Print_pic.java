//5.18 打印图案�?174�?)

package exercise03;

public class Print_pic {

	public static void main(String[] args) {
		int i , j ;
		System.out.println("图案A");
		for (j=0 ; j < 6 ; j++) {
			for (i=1 ; i < j + 2 ; i++) {
				System.out.printf("%3d" , i);
			}
				System.out.println(' '); //换行
		}
		
		System.out.println("图案B");
		for (j=6 ; j > 0 ; j--) {
			for (i=1 ; i < j + 1 ; i++) {
				System.out.printf("%3d" , i);
			}
			System.out.println(' '); //换行
		}

		System.out.println("图案C");
		for (j=6 ; j > 0 ; j--) {
			for (i=1 ; i < j ; i++) {
				System.out.printf("    ");
			}
			for (i=7-j ; i > 0 ; i--) {
				System.out.printf("%3d" , i);
			}
				System.out.println(' '); //换行        
		}

		System.out.println("图案D");
		for (j=6 ; j > 0 ; j--) {
			 for (i = 0 ; i < 6 - j ; i++) System.out.printf("    ");
			 for (i=1 ; i < j + 1 ; i++) System.out.printf("%3d" , i);
			 System.out.println(' ');
		}
	}
}

