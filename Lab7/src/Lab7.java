import java.util.Scanner;

public class Lab7 {

	private Scanner scanner;
	
	private Lab7() {
		scanner = new Scanner(System.in);
		System.out.println("Hello World!");
		System.out.println("What is your name?");
		String input = scanner.nextLine();
		System.out.println(input + ", welcome to my lair.");
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new Lab7();
	}

}
