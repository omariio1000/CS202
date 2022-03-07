import java.util.Scanner;

/* Omar Nassar
 * Portland State University CS202
 * February 28, 2022
 * Cart class for storing an orderer's items
 */

public class Cart {
    public Cart() {//default constructor
        name = null;
        totalPrice = 0;
        cartHead = null;
    }

    public Cart(String name) {//constructor w args
        this.name = name;
        totalPrice = 0;
        cartHead = null;
    }
   
    public void insertItem(Item inserting) {//insert item wrapper
		if (inserting == null) return;
		this.cartHead = insertItem(this.cartHead, inserting);
	}

	private node insertItem(node head, Item inserting) {//insert item recursive
		if (head == null) {
			head = new node(inserting);
            this.totalPrice += head.getItem().getPrice();
			return head;
		}
		head.setNext(insertItem(head.getNext(), inserting));
		return head;
	}

    public void removeItem(String removing, Scanner in) {//remove item wrapper
        if (this.cartHead == null) return;
        this.cartHead = removeItem(this.cartHead, removing, false, in);
    }

    private node removeItem(node head, String name, boolean found, Scanner in) {//remove item recursive
        if (head == null) {
            if (!found) System.out.println("No item found with that name!");
            return head;
        }
        else if (head.getItem().compareName(name)) {
            found = true;
            head.displayCart();
            System.out.println("Are you sure you would like to remove this item? (y/n)");
            String yn = in.nextLine();
            if (yn.equals("y") || yn.equals("Y")) {
                this.totalPrice -= head.getItem().getPrice();
                if (head.getNext() != null) head = head.getNext();
                else head = null;
                System.out.println("Item removed.");
            }
        }
        else head.setNext(removeItem(head.getNext(), name, found, in));
        return head;
    }

    public void display() {//display cart
        System.out.println("\n" + this.name + "'s Cart:");
        displayItems(this.cartHead);
        System.out.printf("\nTotal Price: " + "$" + "%.2f", this.totalPrice);
        System.out.println();
    }

    public void displayItems(node displaying) {//display items in cart
		if (displaying == null) return;
		displaying.displayCart();
		displayItems(displaying.getNext());
	}

    //data members
    String name;
    float totalPrice;
    node cartHead;
}
