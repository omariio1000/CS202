import java.util.ArrayList;
import java.util.Scanner;

/* Omar Nassar
 * Portland State University CS202
 * February 28, 2022
 * Food ordering application with different types of menus
 */

public class Main  {

	private Main() {
		Scanner input = new Scanner(System.in);
		ArrayList<Menu> menus = new ArrayList<Menu>();

		boolean inputting = true;
		System.out.println("Welcome!");
		while (inputting) {
			System.out.println("Please enter the name of your menu file.");
			String menuName = input.nextLine();
			files fileReader = new files();
			Menu newMenu = fileReader.readFile(menuName);
			if (newMenu != null) menus.add(newMenu);
			else System.out.println("No File Found!");

			System.out.println("Would you like to add another menu? (y/n)");
			String yesno = input.nextLine();
			if (!yesno.equals("y") && !yesno.equals("Y")) inputting = false;
		}   
		for (Menu m : menus) {
			m.display();
		}

		input.close();
	}
	
	public static void main(String[] args) {
		new Main();
	}

}