
public class Catering extends Item {
    
    Catering() {
        this.servings = 0;
        this.discount = 0;
    }

    Catering(String name, float price, int servings, float discount) {
        super(name, price);
        this.servings = servings;
        this.discount = discount;
    }

    public void setServings(int servings) {
        this.servings = servings;
    }

    public void setDiscount(float discount) {
        this.discount = discount;
    }

    public void display() {
        super.display();
        System.out.println("\tServes " + servings + "People.");
        if (discount != 0) System.out.println("\tBulk Ordering Discount: " + "%.2f" + discount);
    }

    //data members
    protected int servings;
    protected float discount;
}
