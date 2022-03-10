/*import javax.swing.JFrame;
import javax.swing.JList;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.GridLayout;*/

/* Omar Nassar
 * Portland State University CS202
 * February 28, 2022
 * Menu Class
 */

public class Menu {
	public Menu() {//default constructor
		this.name = null;
		this.cuisine = null;
		this.address = null;
		this.hours = null;
		this.priceRange = 0;
		this.rating = 0;
	}

	//constructor w args
	public Menu(String name, String cuisine, String address, String hours, int priceRange, int rating) {
		this.name = name;
		this.cuisine = cuisine;
		this.address = address;
		this.hours = hours;
		this.priceRange = priceRange;
		this.rating = rating;
	}

	public void display() {//displaying menu
		System.out.println(this.name + " (" + this.cuisine + " Food)");
		System.out.println(this.address);
		System.out.println("Hours: " + this.hours);
		System.out.print("Price: ");
		for (int i = 0; i < priceRange; i++) {
			System.out.print("$");
		}
		System.out.println(" Rating: " + rating + " stars");
		System.out.println("Menu:");
		if (this.itemList != null) displayItems(this.itemList);
	}

	public void displayItems(node displaying) {//displaying menu items
		if (displaying == null) return;
		displaying.display();
		displayItems(displaying.getNext());
	}

	/*public void visualDisplay() {
		JFrame visualMenu = new JFrame(this.name);
		visualMenu.setSize(500, 500);
		visualMenu.setLayout(new BorderLayout());
		Container shopDetails = new Container();
		Container items = new Container();
		Container itemNames = new Container();
		Container itemDetails = new Container();

		items.setLayout(new BorderLayout());
		shopDetails.setLayout(new GridLayout());
		itemNames.setLayout(new GridLayout());
		itemDetails.setLayout(new GridLayout());

		JList itemJList = new JList<Item>();
		node allItems = itemList;
		while (allItems != null) {
			itemJList.addElement(allItems.getItem());
			allItems = allItems.getNext();
		}

		visualMenu.setVisible(true);
	}*/

	public void setDetails(String name, String cuisine, String address, String hours, int priceRange, int rating) {
		this.name = name;
		this.cuisine = cuisine;
		this.address = address;
		this.hours = hours;
		this.priceRange = priceRange;
		this.rating = rating;
	}

	public void insertItem(Item inserting) {//inserting item wrapper
		if (inserting == null) return;
		this.itemList = insertItem(this.itemList, inserting);
	}

	private node insertItem(node head, Item inserting) {//inserting item recursive
		if (head == null) {
			head = new node(inserting);
			return head;
		}
		head.setNext(insertItem(head.getNext(), inserting));
		return head;
	}

	public Item retrieveItem(String name) {//retrieving item wrapper
		if (this.itemList == null) return null;
		node ret = retrieveItem(this.itemList, name);
		if (ret == null) return null;
		return ret.getItem();
	}

	private node retrieveItem(node head, String name) {//retrieving item recursive
		if (head == null) return head;
		if (head.getItem().compareName(name)) return head;
		return retrieveItem(head.getNext(), name);
	}

	public boolean compare(String name) {
		if (this.name.equals(name)) return true;
		return false;
	}

	public int compareTree(Menu comp) {
		int result = (this.cuisine.compareTo(comp.cuisine));
		if (result == 0) return 0;
		else if (result > 0) return 1;
		else return -1;
	}

	public int compareTree(String cuisine) {
		int result = (this.cuisine.compareTo(cuisine));
		if (result == 0) return 0;
		else if (result > 0) return 1;
		else return -1;
	}

	//data members
	protected String name;
	protected String cuisine;
	protected String address;
	protected String hours;
	protected int priceRange;
	protected int rating;	
	protected node itemList;
}
