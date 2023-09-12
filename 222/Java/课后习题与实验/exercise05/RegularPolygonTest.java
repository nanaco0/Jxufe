package exercise05;

public class RegularPolygonTest {

	public static void main(String[] args) {
		RegularPolygon RP00 = new RegularPolygon();
		System.out.printf("RP00：\t 周长�?%.2f \t 面积�?%.2f \n", RP00.getPerimeter(), RP00.getArea());
		RegularPolygon RP01 = new RegularPolygon(6, 4);
		System.out.printf("RP01：\t 周长�?%.2f \t 面积�?%.2f \n", RP01.getPerimeter(), RP01.getArea());
		RegularPolygon RP02 = new RegularPolygon(10, 4, 5.6, 7.8);
		System.out.printf("RP02：\t 周长�?%.2f \t 面积�?%.2f \n", RP02.getPerimeter(), RP02.getArea());
	}

}
