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
		while (inputting) {//adding menus to the arraylist
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

		for (Menu m : menus) {//displaying all menus
			m.display();
		}

		System.out.println("What is your name?");
		String orderName = input.nextLine();
		Cart orderer = new Cart(orderName);
		boolean running = true;

		while (running) {//running main program
			System.out.println("\nWhat would you like to do?");
			System.out.println("1: Add item to cart");
			System.out.println("2: Remove item from cart");
			System.out.println("3: Display your cart");
			System.out.println("4: Display a menu");
			System.out.println("5: Checkout");
			
			int option = Integer.parseInt(input.nextLine());
			if (option == 1) {//adding item to cart
				boolean ordering = true;
				while (ordering) {//selecting item
					System.out.println("Which menu would you like to order from?");
					Menu selected = null;
					String selectedName = input.nextLine();
					for (Menu m : menus) {
						if (m.compare(selectedName)) {
							selected = m;
							break;
						}
					}
					if (selected != null) {
						System.out.println("Would you like to view the menu? (y/n)");
						String yesno = input.nextLine();
						if (yesno.equals("y") || yesno.equals("Y")) selected.display();
						boolean selectingItems = true;
						while (selectingItems) {//adding items from this menu
							System.out.println("What item would you like to order?");
							String itemName = input.nextLine();
							Item orderItem = selected.retrieveItem(itemName);
							if (orderItem != null) {
								Item itemCopy = null;
								int type = 0;
								if (orderItem instanceof Customizable) {
									itemCopy = new Customizable();
									type = 1;
								}
								else if (orderItem instanceof Spice) {
									itemCopy = new Spice();
									type = 2;
								}
								else if (orderItem instanceof Catering) {
									itemCopy = new Catering();
									type = 3;
								}
								else {//class is of different type
									System.out.println("Unknown Error Occured.");
									break;
								}

								itemCopy.copy(orderItem);

								System.out.println("Would you like to view the item? (y/n)");
								yesno = input.nextLine();
								if (yesno.equals("y") || yesno.equals("Y")) itemCopy.display();

								if (type == 1) {
									System.out.println("Would you like any toppings? (y/n)");
									yesno = input.nextLine();
									boolean choosingToppings = false;
									if (yesno.equals("y") || yesno.equals("Y")) choosingToppings = true;
									while (choosingToppings) {
										System.out.println("What topping would you like to add?");
										String toppingName = input.nextLine();
										((Customizable) itemCopy).chooseTopping(toppingName);
										System.out.println("Would you like to add another topping? (y/n)");
										yesno = input.nextLine();
										if (!yesno.equals("y") && !yesno.equals("Y")) choosingToppings = false;
									}
									orderer.insertItem(itemCopy);
								}
								else if (type == 2) {
									System.out.println("What spice level would you like to select?");
									int spice = Integer.parseInt(input.nextLine());
									((Spice) itemCopy).setSelectedSpice(spice);
									orderer.insertItem(itemCopy);
								}
								else if (type == 3) {
									System.out.println("How many servings would you like to order?");
									int servings = Integer.parseInt(input.nextLine());
									((Catering) itemCopy).setSelectedServings(servings);
									orderer.insertItem(itemCopy);
								}
								else {//of other class type
									System.out.println("Unknown Error Occured.");
									break;
								}
							}
							else System.out.println("There is no item with that name!");

							System.out.println("Would you like to order another item from this menu? (y/n)");
							yesno = input.nextLine();
							if (!yesno.equals("y") && !yesno.equals("Y")) selectingItems = false;
						}
					}
					else System.out.println("No menu found with that name!");

					System.out.println("Would you like to order from another menu? (y/n)");
					String yesno = input.nextLine();
					if (!yesno.equals("y") && !yesno.equals("Y")) ordering = false;
				}
			}
			else if (option == 2) {//removing item from cart
				System.out.println("What item would you like to remove?");
				String removing = input.nextLine();
				orderer.removeItem(removing, input);
			}
			else if (option == 3) orderer.display(); //displaying cart
			else if (option == 4) {//displaying a mnu
				System.out.println("What menu would you like to display?");
				String menuName = input.nextLine();
				Menu selected = null;
				for (Menu m : menus) {
					if (m.compare(menuName)) {
						selected = m;
						break;
					}
				}
				if (selected != null) selected.display();
				else System.out.println("No menu found with that name.");
			}
			else if (option == 5) {//checking out (quit)
				orderer.display();
				System.out.println("Thanks for your order!");
				running = false;
			}
			else System.out.println("Invalid Input.");
		}
		input.close();
	}

	public static void main(String[] args) {
		new Main();
	}

}