package exercise06;

import java.util.*;

public class MyRectangle2D {

    public MyRectangle2D() {
        this.x = 0;
        this.y = 0;
        this.height = 1;
        this.width = 1;
    }

    private double x;

    private double y;

    private double width;

    public double getX() {
        return x;
    }

    public void setX(double x) {
        this.x = x;
    }

    public double getY() {
        return y;
    }

    public void setY(double y) {
        this.y = y;
    }

    public double getWidth() {
        return width;
    }

    public void setWidth(double width) {
        this.width = width;
    }

    public double getHeight() {
        return height;
    }

    public void setHeight(double height) {
        this.height = height;
    }

    /**
     *
     */
    private double height;

    public MyRectangle2D(double x, double y, double width, double height) {
        // TODO implement here
        this.x = x;
        this.y = y;
        this.width = width;
        this.height = height;
    }

    public double getArea() {
        // TODO implement here
        return height * width;
    }

    public double getPerimeter() {
        // TODO implement here
        return (height + width) * 2;
    }

    public boolean contains(double x, double y) {
        // TODO implement here
        //长方形判断：点到中心点距离x<width/2;;;y<height/2
        return Math.abs(x - this.x) < width / 2 && Math.abs(y - this.y) < height / 2;
    }

    public boolean contains(MyRectangle2D r) {
        // TODO implement here
        //包含判断：俩中心点距离小于宽距离和高距离�?
        return Math.abs(this.x - r.getX()) <= Math.abs((this.width - r.width) / 2)&&Math.abs(this.y - r.y )<= Math.abs((this.height - r.height) / 2);
    }

    public boolean overLaps(MyRectangle2D r) {
        // TODO implement here
        //重叠判断：点距离大于宽之差，高之差，小于宽高之和
        boolean overlaps1=Math.abs(this.x - r.getX()) > Math.abs((this.width - r.width) / 2)&&Math.abs(this.y - r.y )> Math.abs((this.height - r.height) / 2);
        boolean overlaps2=Math.abs(this.x - r.getX()) < Math.abs((this.width + r.width) / 2)&&Math.abs(this.y - r.y )< Math.abs((this.height + r.height) / 2);
        return overlaps1&&overlaps2;
    }

}
