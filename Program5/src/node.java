/* Omar Nassar
 * Portland State University CS202
 * February 28, 2022
 * node class that stores food items, used for both menu and cart
 */

public class node {
	
    node() {
        item = null;
    }

    node(Item item) {
        this.item = item;
    }

    public node getNext() {
        return this.next;
    }

    public void setNext(node next) {
        this.next = next;
    }

    public Item getItem() {
        return this.item;
    }

    public void setItem(Item item) {
        this.item = item;
    }
    
    public void display() {
        this.item.display();
    }

    public void displayCart() {
        this.item.displayCart();
    }

    //data members
    protected Item item;
    protected node next;
}