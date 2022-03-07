/* Omar Nassar
 * Portland State University CS202
 * February 28, 2022
 * Foods that can be ordered in bulk
 */

public class Catering extends Item {
    
    Catering() {//default constructor
        this.servings = 0;
        this.discount = 0;
        this.selectedServings = 0;
        this.finalPrice = 0;
    }

    Catering(String name, float price, int servings, float discount) {//constructor with args
        super(name, price);
        this.servings = servings;
        this.discount = discount;
        this.selectedServings = 0;
        this.finalPrice = price;
    }

    public void setServings(int servings) {
        this.servings = servings;
    }

    public void setDiscount(float discount) {
        this.discount = discount;
    }

    public void display() {//display for menu
        super.display();
        System.out.println("\tServes " + servings + " People.");
        if (discount != 0) {
            System.out.printf("\tBulk Ordering Discount: $" + "%.2f", discount);
            System.out.println("\n");
        }
    }

    public void displayCart() {//display for cart
        System.out.print(this.name + " (serves " + (this.servings * this.selectedServings) + ")");
        System.out.printf(" - $" + "%.2f", this.finalPrice);
        float totalDiscount = this.selectedServings * this.discount;
        System.out.printf(" ($" + "%.2f", totalDiscount);
        System.out.println(" total discount)");
    }

    public void setSelectedServings(int servings) {
        this.selectedServings = servings;
        float finalDiscount = servings * this.discount;
        this.finalPrice -= finalDiscount;
    }

    public void copyItem(Catering item) {//copy function
        this.name = item.name;
        this.price = item.price;
        this.servings = item.servings;
        this.discount = item.discount;
        this.selectedServings = 0;
        this.finalPrice = this.price;
    }

    public float getPrice() {
        return finalPrice;
    }

    //data members
    protected int servings;
    protected float discount;
    protected int selectedServings;
    protected float finalPrice;
}
