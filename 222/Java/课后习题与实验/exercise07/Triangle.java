package exercise07;

public class Triangle extends GeometricObject{
    // 3个数据域
    public double side1 = 1;
    public double side2 = 1;
    public double side3 = 1;

    // 无参构造
    public Triangle(){
    }
    // 有参构造
    public Triangle(double side1, double side2, double side3){
        this.side1 = side1;
        this.side2 = side2;
        this.side3 = side3;
    }

    // 访问器方法
    public double getSide1() {
        return side1;
    }
    public double getSide2() {
        return side2;
    }
    public double getSide3() {
        return side3;
    }

    // 返回三角形面积的getArea()
    public double getArea(){
        double s = (side1 + side2 + side3) / 2;
        return Math.pow(s * (s - side1) * (s - side2) * (s - side3), 0.5);
    }

    // 返回三角形周长
    public double getPerimeter(){
        return side1 + side2 + side3;
    }

    // 返回该三角形的字符串描述
    @Override
    public String toString(){
        return "Triangle: side1 = " + side1 + " side2 = " + side2 + " side = " + side3;
    }
}
