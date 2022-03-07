import java.util.Scanner;

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
        this.cartHead = removeItem(this.cartHead, removing, false);
    }

    private node removeItem(node head, String name, boolean found) {
        if (head == null) {
            if (!found) System.out.println("No item found with that name!");
            return head;
        }
        else if (head.getItem().compareName(name)) {
            found = true;
            head.displayCart();
            System.out.println("Are you sure you would like to remove this item? (y/n)");
            Scanner in = new Scanner(System.in);
            String yn = in.nextLine();
            if (yn.equals("y") || yn.equals("Y")) {
                this.totalPrice -= head.getItem().getPrice();
                if (head.getNext() != null) head = head.getNext();
                else head = null;
                System.out.println("Item removed.");
            }
        }
        else head.setNext(removeItem(head.getNext(), name, found));
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
