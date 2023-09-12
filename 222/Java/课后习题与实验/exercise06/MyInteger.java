package exercise06;

import java.util.*;

public class MyInteger {

    public MyInteger() {
    }

    private int value;

    public MyInteger(int value) {
        // TODO implement here
        this.value = value;
    }

    public int get() {
        // TODO implement here
        return this.value;
    }

    public boolean isEven() {
        // TODO implement here
        if (get() % 2 == 0)
            return true;
        else
            return false;
    }

    public boolean isOdd() {
        // TODO implement here
        if (get() % 2 == 1)
            return true;
        else
            return false;
    }

    public boolean isPrime() {
        // TODO implement here
        boolean is = true;
        for (int i = 2; i < get(); i++) {
            if (get() % i == 0) {
                is = false;
                break;
            }
        }
        return is;
    }

    public static boolean isEven(int value) {
        // TODO implement here
        if (value % 2 == 0)
            return true;
        else
            return false;
    }

    public static boolean isOdd(int value) {
        // TODO implement here
        if (value % 2 == 1)
            return true;
        else
            return false;
    }

    public static boolean isPrime(int value) {
        // TODO implement here
        boolean is = true;
        for (int i = 2; i < value; i++) {
            if (value % i == 0) {
                is = false;
                break;
            }
        }
        return is;
    }

    public static boolean isEven(MyInteger value) {
        // TODO implement here
        if (value.get() % 2 == 0)
            return true;
        else
            return false;
    }

    public static boolean isOdd(MyInteger value) {
        // TODO implement here
        if (value.get() % 2 == 1)
            return true;
        else
            return false;
    }

    public static boolean isPrime(MyInteger value) {
        // TODO implement here
        boolean is = true;
        for (int i = 2; i < value.get(); i++) {
            if (value.get() % i == 0) {
                is = false;
                break;
            }
        }
        return is;
    }

    public boolean equals(int value) {
        // TODO implement here
        return value==get();
    }

    public boolean equals(MyInteger value) {
        // TODO implement here
        return value.value==get();
    }

    public static int parseInt(char[] c) {
        // TODO implement here
        return Integer.parseInt(new String(c));
    }

    public static int parseInt(String str) {
        // TODO implement here
        return Integer.parseInt(str);
    }

}
