/* Omar Nassar
 * Portland State University CS202
 * February 28, 2022
 * Abstract food item class
 */

abstract class Item {
    Item() {//default constructor
        this.name = null;
        this.price = 0;
    }

    Item(String name, float price) {//constructor w args
        this.name = name;
        this.price = price;
    }

    public float getPrice() {
        return price;
    }

    public boolean compareName(String name) {
        if (this.name.equals(name)) return true;
        return false;
    }

    public void display() {//menu display
        System.out.printf("\n" + this.name + " - $" + "%.2f", price);
        System.out.println();
    }

    abstract void displayCart(); //abstract cart display

    public void copy(Item copying) {//copy func to call derived copy
        if (copying instanceof Customizable) ((Customizable) this).copyItem(((Customizable) copying));
        else if (copying instanceof Spice) ((Spice) this).copyItem(((Spice) copying));
        else if (copying instanceof Catering) ((Catering) this).copyItem(((Catering) copying));
        else return;
    }

    //data members
    protected String name;
    protected float price;
}
