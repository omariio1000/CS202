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
		System.out.println(this.name + " (" + this.cuisine + "Food)");
		System.out.println(this.address + "Hours: " + this.hours);
		System.out.println();
		for (int i = 0; i < priceRange; i++) {
			System.out.print("$");
		}
		System.out.println("Rating: " + rating + " stars");
	}


	public void setDetails(String name, String cuisine, String address, String hours, int priceRange, int rating) {
		this.name = name;
		this.cuisine = cuisine;
		this.address = address;
		this.hours = hours;
		this.priceRange = priceRange;
		this.rating = rating;
	}


	//data members
	protected String name;
	protected String cuisine;
	protected String address;
	protected String hours;
	protected int priceRange;
	protected int rating;	
}
