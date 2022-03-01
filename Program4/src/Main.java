/* Omar Nassar
 * Portland State University CS202
 * February 28, 2022
 * Food ordering application with different types of menus
 */

public class Main  {

	private Main() {
		Spice tikka = new Spice("Tikka", (float) 12.50, 5);
		Customizable pizza = new Customizable("pizza", (float) 11.50);
		pizza.addFreeTopping("Cheese");
		pizza.addFreeTopping("Olives");
		pizza.addExtraTopping("chicken", (float) 1.0);
		Menu bollywood = new Menu("Bollywood Eats", "Indian", "1234 Hollywood Blvd.", "8AM - 10PM Mon-Fri, 10AM - 8PM Sat-Sun", 2, 4);
		

		bollywood.insertItem(tikka);
		bollywood.insertItem(pizza);
		bollywood.display();

	}
	
	public static void main(String[] args) {
		new Main();
	}

}
