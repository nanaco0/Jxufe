package exercise12;

import java.util.Date;

public abstract class GeometricObject {
    // 三个数据域
    String color;
    boolean filled;
    Date dateCreated;

    // 无参构造方法
    protected GeometricObject(){
        dateCreated = new Date();
    }
    // 有参构造方法
    protected GeometricObject(String color, boolean filled){
        this.color = color;
        this.filled = filled;
        dateCreated = new Date();
    }

    // getter and setter 颜色值
    public String getColor() {
        return color;
    }
    public void setColor(String color) {
        this.color = color;
    }

    // getter and setter filled
    public boolean isFilled() {
        return filled;
    }
    public void setFilled(boolean filled) {
        this.filled = filled;
    }

    // 获取DateCreated
    public Date getDateCreated() {
        return dateCreated;
    }

    // toString
    @Override
    public String toString() {
        return "GeometricObject{" +
                "color='" + color + '\'' +
                ", filled=" + filled +
                ", dateCreated=" + dateCreated +
                '}';
    }
    
    public abstract double getArea();
    
    public abstract double getPerimeter();
}

