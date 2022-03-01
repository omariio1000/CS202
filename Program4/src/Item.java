/* Omar Nassar
 * Portland State University CS202
 * February 28, 2022
 * Abstract food item class
 */

abstract class Item {
    Item() {
        this.name = null;
        this.price = 0;
    }

    Item(String name, float price) {
        this.name = name;
        this.price = price;
    }

    public void display() {
        System.out.printf(this.name + " - $" + "%.2f", price);
        System.out.println();
    }

    //data members
    protected String name;
    protected float price;
}
