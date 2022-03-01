
public class Spice extends Item {
    Spice() {
        this.spice = 0;
    }
    
    Spice(String name, float price, int spice) {
        super(name, price);
        this.spice = spice;
        if (this.spice > 10) this.spice = 10;
    }

    public void setSpice(int spice) {
        this.spice = spice;
        if (this.spice > 10) this.spice = 10;
    }

    public void display() {
        super.display();
        System.out.println("\tSpice Level:" + this.spice);
    }

    //data members
    protected int spice;
}
