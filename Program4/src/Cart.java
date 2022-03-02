public class Cart {
    public Cart() {
        name = null;
        totalPrice = 0;
        cartHead = null;
    }

    public Cart(String name) {
        this.name = name;
        totalPrice = 0;
        cartHead = null;
    }
   
    public void insertItem(Item inserting) {
		if (inserting == null) return;
		this.cartHead = insertItem(this.cartHead, inserting);
	}

	private node insertItem(node head, Item inserting) {
		if (head == null) {
			head = new node(inserting);
            this.totalPrice += head.getItem().getPrice();
			return head;
		}
		head.setNext(insertItem(head.getNext(), inserting));
		return head;
	}

    public void removeItem(String removing) {
        if (this.cartHead == null) return;
        this.cartHead = removeItem(this.cartHead, removing);
    }

    private node removeItem(node head, String name) {
        if (head == null) return head;
        else if (head.getItem().compareName(name)) {
            this.totalPrice -= head.getItem().getPrice();
            if (head.getNext() != null) head = head.getNext();
            else head = null;
        }
        else head.setNext(removeItem(head.getNext(), name));
        return head;
    }

    public void display() {
        System.out.println("\n" + this.name + "'s Cart:");
        displayItems(this.cartHead);
        System.out.printf("\nTotal Price: " + "$" + "%.2f", this.totalPrice);
        System.out.println();
    }

    public void displayItems(node displaying) {
		if (displaying == null) return;
		displaying.displayCart();
		displayItems(displaying.getNext());
	}

    //data members
    String name;
    float totalPrice;
    node cartHead;
}
