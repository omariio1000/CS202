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

    //data members
    protected Item item;
    protected node next;
}