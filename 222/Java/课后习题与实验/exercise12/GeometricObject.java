package exercise12;

import java.util.Date;

public abstract class GeometricObject {
    // ����������
    String color;
    boolean filled;
    Date dateCreated;

    // �޲ι��췽��
    protected GeometricObject(){
        dateCreated = new Date();
    }
    // �вι��췽��
    protected GeometricObject(String color, boolean filled){
        this.color = color;
        this.filled = filled;
        dateCreated = new Date();
    }

    // getter and setter ��ɫֵ
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

    // ��ȡDateCreated
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

