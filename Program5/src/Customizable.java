import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;

/* Omar Nassar
 * Portland State University CS202
 * February 28, 2022
 * Customizable food item derived class
 */

public class Customizable extends Item {
    Customizable() {//default constructor
        super();
        freeToppings = new ArrayList<String>();
        extraToppings = new HashMap<String, Float>();
        selectedToppings = new ArrayList<String>();
        finalPrice = 0;
    }

    Customizable(String name, float price) {//constructor w args
        super(name, price);
        freeToppings = new ArrayList<String>();
        extraToppings = new HashMap<String, Float>();
        selectedToppings = new ArrayList<String>();
        finalPrice = price;
    }

    //constructor w args and arraylist and map (not used)
    Customizable(String name, float price, ArrayList<String> freeToppings, HashMap<String, Float> extraToppings) {
        super(name, price);
        this.freeToppings = freeToppings;
        this.extraToppings = extraToppings;
        selectedToppings = new ArrayList<String>();
    } 

    public void addFreeTopping(String topping) {
        this.freeToppings.add(topping);
    }

    public void addExtraTopping(String topping, float price) {
        this.extraToppings.put(topping, price);
    }

    public void display() {//menu display
        super.display();
        System.out.print("\tFree Toppings: ");
        for (int i = 0; i < this.freeToppings.size(); i++) {
            System.out.print(this.freeToppings.get(i));
            if (i != this.freeToppings.size() - 1) System.out.print(", ");
        }
        System.out.println();
        System.out.println("\tOther Toppings:");
        for (Map.Entry<String, Float> topping : this.extraToppings.entrySet()) {
            System.out.printf("\t\t" + topping.getKey() + " - $" + "%.2f", topping.getValue());
            System.out.println();
        } 
    }

    public void displayCart() {//cart display
        System.out.print("\n" + this.name);
        if (!this.selectedToppings.isEmpty()) {
            System.out.print(" with ");
            for (int i = 0; i < this.selectedToppings.size(); i++) {
                System.out.print(this.selectedToppings.get(i));
                if (i != this.selectedToppings.size() - 1) System.out.print(", ");
            }
        }
        System.out.printf(" - $" + "%.2f", this.finalPrice);
        System.out.println();
    }

    public void chooseTopping(String name) {//selecting a topping
        if (name.equals("")) return;
        for (String topping : this.freeToppings) {
            if (topping.equals(name)) {
                this.selectedToppings.add(topping);
                return;
            }
        }

        for  (Map.Entry<String, Float> topping : this.extraToppings.entrySet()) {
            if (topping.getKey().equals(name)) {
                this.selectedToppings.add(topping.getKey());
                this.finalPrice += topping.getValue();
                return;
            }
        }

        System.out.println("No topping found with that name!");
    }

    public void copyItem(Customizable item) {//copy function
        this.name = item.name;
        this.price = item.price;
        this.freeToppings = item.freeToppings;
        this.extraToppings = item.extraToppings;
        this.selectedToppings = new ArrayList<String>();
        this.finalPrice = this.price;
    }

    public float getPrice() {
        return finalPrice;
    }

    //data members
    protected ArrayList<String> freeToppings;
    protected Map<String, Float> extraToppings;
    protected ArrayList<String> selectedToppings;
    protected float finalPrice;
}
