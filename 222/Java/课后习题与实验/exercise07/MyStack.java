package exercise07;

import java.util.ArrayList;
import java.util.Scanner;

public class MyStack extends ArrayList<Object>{
	public boolean isEmpty() {
		return this.isEmpty();
	}
	public int getSize() {
		return this.size();
	}
	public Object peek() {
		return this.get(getSize() - 1);
	}
	public Object pop(){
		Object object = this.get(this.size() - 1);
		this.remove(this.size() - 1);
		return object;
	}
	public void push(Object object){
		this.add(object);
	}
	@Override
	public String toString() {
		return "Stack: " + this.toString();
	}
		
		
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.println("请输�?5个元素：");
		MyStack myStack = new MyStack();
		for(int i = 0; i < 5; i++){
			myStack.push(input.next());
		}
		System.out.println("逆序显示�?");
		for(int i = 0; i < 5; i++){
			System.out.print(myStack.pop());
			System.out.print(" ");
		}
		input.close();
	}
}
