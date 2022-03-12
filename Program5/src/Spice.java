/* Omar Nassar
 * Portland State University CS202
 * February 28, 2022
 * Foods with various spice levels
 */

public class Spice extends Item {
    Spice() {//default constructor
        this.spice = 0;
        this.selectedSpice = 0;
    }
    
    Spice(String name, float price, int spice) {//constructor with args
        super(name, price);
        this.spice = spice;
        if (this.spice > 10) this.spice = 10;
        this.selectedSpice = 0;
    }

    public void setSpice(int spice) {
        this.spice = spice;
        if (this.spice > 10) this.spice = 10;
    }

    public void display() {//display for menu
        super.display();
        System.out.println("\tSpice Level: 0 - " + this.spice);
    }

    public void displayCart() {//display for cart
        System.out.print(this.name + " with spice level " + this.selectedSpice);
        System.out.printf(" - $" + "%.2f", this.price);
        System.out.println();
    }

    public void setSelectedSpice(int inSpice) {
        this.selectedSpice = inSpice;
        if (this.selectedSpice > this.spice) this.selectedSpice = this.spice;
    }

    public void copyItem(Spice item) {//copy function
        this.name = item.name;
        this.price = item.price;
        this.spice = item.spice;
        this.selectedSpice = 0;
    }

    //data members
    protected int spice;
    protected int selectedSpice;
}
