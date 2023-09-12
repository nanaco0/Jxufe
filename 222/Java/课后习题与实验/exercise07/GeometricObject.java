package exercise07;

import java.util.Date;

public class GeometricObject {
    // ����������
    String color;
    boolean filled;
    Date dateCreated;

    // �޲ι��췽��
    public GeometricObject(){
        dateCreated = new Date();
    }
    // �вι��췽��
    public GeometricObject(String color, boolean filled){
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
        return "Test01_GeometricObject{" +
                "color='" + color + '\'' +
                ", filled=" + filled +
                ", dateCreated=" + dateCreated +
                '}';
    }
}

