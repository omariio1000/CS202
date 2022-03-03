/* Omar Nassar
 * Portland State University CS202
 * February 28, 2022
 * Food ordering application with different types of menus
 */

public class Main  {

	private Main() {
		files fileReader = new files();
		Menu newMenu = fileReader.readFile("sampleMenu.txt");
		if (newMenu == null) System.exit(1);
		newMenu.display();

		Cart orderer = new Cart("Omar");
		
		Item copying = newMenu.retrieveItem("Pizza");
		Item newItem = null;
		if (copying != null) {
			if (copying instanceof Customizable) newItem = new Customizable();
			else if (copying instanceof Spice) newItem = new Spice();
			else if (copying instanceof Catering) newItem = new Catering();
			
			if (newItem != null) newItem.copy(copying);
		}

		((Customizable) newItem).chooseTopping("chicken");
		((Customizable) newItem).chooseTopping("Olives");

		orderer.insertItem(newItem);
		orderer.display();
       

	}
	
	public static void main(String[] args) {
		new Main();
	}

}