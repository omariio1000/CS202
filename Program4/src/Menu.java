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
	public Menu() {
		this.name = null;
		this.cuisine = null;
		this.address = null;
		this.hours = null;
		this.priceRange = 0;
		this.rating = 0;
	}

	public Menu(String name, String cuisine, String address, String hours, int priceRange, int rating) {
		this.name = name;
		this.cuisine = cuisine;
		this.address = address;
		this.hours = hours;
		this.priceRange = priceRange;
		this.rating = rating;
	}

	public void display() {
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

	public void displayItems(node displaying) {
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

	public void insertItem(Item inserting) {
		if (inserting == null) return;
		this.itemList = insertItem(this.itemList, inserting);
	}

	private node insertItem(node head, Item inserting) {
		if (head == null) {
			head = new node(inserting);
			return head;
		}
		head.setNext(insertItem(head.getNext(), inserting));
		return head;
	}

	public Item retrieveItem(String name) {
		if (this.itemList == null) return null;
		node ret = retrieveItem(this.itemList, name);
		if (ret == null) return null;
		return ret.getItem();
	}

	public node retrieveItem(node head, String name) {
		if (head == null) return head;
		if (head.getItem().compareName(name)) return head;
		return retrieveItem(head.getNext(), name);
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
