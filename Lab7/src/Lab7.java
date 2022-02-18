import java.util.Scanner;
import java.util.*;

public class Lab7 {

	protected Scanner scanner = null;

	private Lab7() {
		/*scanner = new Scanner(System.in);
		System.out.println("How many people would you like to add?");
		int max = scanner.nextInt();
		person[] people = new person[max];
		for (int i = 0; i < people.length; i++) {
			people[i] = new person();
			people[i].input();
		}
		for (int i = 0; i < people.length; i++) {
			people[i].display();
			people[i].compare("Omar");
		}*/
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new Lab7();
	}

}

class person {
	private Scanner scanner = null;

	public person() {
		this.name = null;
		this.age = 0;
		this.wage = 0;
		this.grades = null;
		this.classes = null;
	}

	public void input() {
		this.scanner = new Scanner(System.in);
		System.out.println("Please input your name, age, and wage.");
		this.name = this.scanner.next();
		this.age = this.scanner.nextInt();
		this.wage = this.scanner.nextFloat();
		this.scanner.nextLine();
		System.out.println("How many classes are you taking?");
		int classCount = this.scanner.nextInt();
		this.classes = new String[classCount];
		this.grades = new float[classCount];
		for (int i = 0; i < classCount; i++) {
			System.out.println("Enter your class name followed by the grade in that class (%)");
			this.classes[i] = this.scanner.next();
			this.grades[i] = this.scanner.nextFloat();
		}
	}

	public void display() {
		System.out.println("Name: " + this.name + " Age: " + this.age + " Wage: $" + this.wage);
		for (int i = 0; i < this.classes.length; i++) {
			System.out.println(this.classes[i] + " Grade: " + this.grades[i] + "%");
		}
	}

	public boolean compare(String comp) {
		if (comp.equals(this.name))
			return true;
		return false;
	}

	protected float[] grades;
	protected String[] classes;
	protected String name;
	protected int age;
	protected float wage;
}

class node {
	public node() {
		this.data = null;
		this.next = null;
	}

	public node(person obj) {
		this.data = obj;
		this.next = null;
	}

	public node getNext() {
		return next;
	}

	public void setNext(node obj) {
		this.next = obj;
	}

	public person getData() {
		return this.data;
	}

	public void setData(person obj) {
		this.data = obj;
	}

	public node next;
	protected person data;
}

class LinkedList {
	public LinkedList() {
		this.head = null;
	}

	public void insertData(node obj) {
		if (this.head == null) {
			this.head = obj;
			return;
		}
		else insertData(this.head.getNext(), obj);
		return;
	}

	public void insertData(node current, node obj) {
		if (current == null) {
			current = null;
			return;
		} 
		else insertData(this.head.getNext(), obj);
		return;
	}
	
	public void display() {
		if (this.head == null) return;
		display(this.head);
		return;
	}
	
	public void display(node displaying) {
		if (displaying == null) return;
		displaying.getData().display();
		display(displaying.getNext());
		return;
	}

	protected node head;
}
