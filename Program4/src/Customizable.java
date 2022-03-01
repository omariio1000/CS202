import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;

/* Omar Nassar
 * Portland State University CS202
 * February 28, 2022
 * Customizable food item derived class
 */

public class Customizable extends Item {
    Customizable() {
        super();
        freeToppings = new ArrayList<String>();
        extraToppings = new HashMap<String, Float>();
    }

    Customizable(String name, float price) {
        super(name, price);
        freeToppings = new ArrayList<String>();
        extraToppings = new HashMap<String, Float>();
    }

    Customizable(String name, float price, ArrayList<String> freeToppings, HashMap<String, Float> extraToppings) {
        super(name, price);
        this.freeToppings = freeToppings;
        this.extraToppings = extraToppings;
    } 

    public void addFreeTopping(String topping) {
        this.freeToppings.add(topping);
    }

    public void addExtraTopping(String topping, float price) {
        this.extraToppings.put(topping, price);
    }

    public void display() {
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

    //data members
    protected ArrayList<String> freeToppings;
    protected Map<String, Float> extraToppings;
}
