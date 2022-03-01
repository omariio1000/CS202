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
		this.itemList = insertItem(itemList, inserting);
	}

	public node insertItem(node head, Item inserting) {
		if (head == null) {
			head = new node(inserting);
			return head;
		}
		head.setNext(insertItem(head.getNext(), inserting));
		return head;
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
