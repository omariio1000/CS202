import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

/* Omar Nassar
 * Portland State University CS202
 * February 28, 2022
 * class for reading files, just wanted to keep clutter out of main
 */

public class files {
    files() {
        this.fileReader = null;
    }

    public Menu readFile(String fileName) {//reading file member function
        Menu newMenu;
        try {
            fileReader = new BufferedReader(new FileReader(fileName));
            String line;
            line = fileReader.readLine();
            String[] restuarant = line.split("\\|");
            /*for (int i = 0; i < restuarant.length; i++) {
                System.out.println(restuarant[i]);
            }*/
            newMenu = new Menu(restuarant[0], restuarant[1], restuarant[2], restuarant[3], Integer.parseInt(restuarant[4]), Integer.parseInt(restuarant[5]));
            while ((line = fileReader.readLine()) != null) {
                String[] parsed = line.split("\\|");
                if (parsed[0].equals("Customizable")) {//customizable items
                    Customizable newCust = new Customizable(parsed[1], Float.parseFloat(parsed[2]));
                    String[] freeToppings = parsed[3].split(",");
                    for (int i = 0; i < freeToppings.length; i++) {//parsing free toppings
                        newCust.addFreeTopping(freeToppings[i]);
                    }

                    String[] paidToppings = parsed[4].split(",");
                    for (int i = 0; i < paidToppings.length; i++) {//parsing paid toppings
                        String[] toppingPrice = paidToppings[i].split("-");
                        newCust.addExtraTopping(toppingPrice[0], Float.parseFloat(toppingPrice[1]));
                    }
                    newMenu.insertItem(newCust);
                }
                else if (parsed[0].equals("Spice")) {//spicy items
                    Spice newSpice = new Spice(parsed[1], Float.parseFloat(parsed[2]), Integer.parseInt(parsed[3]));
                    newMenu.insertItem(newSpice);
                }
                else if (parsed[0].equals("Catering")) {//catering items
                    Catering newCater = new Catering(parsed[1], Float.parseFloat(parsed[2]), Integer.parseInt(parsed[3]), Float.parseFloat(parsed[4]));
                    newMenu.insertItem(newCater);
                }
                else {
                    System.out.println("Incompatible File.");
                    return null;
                }
            }
            fileReader.close();
        }
        catch (IOException e) {//catching errors
            return null;
        }    
        return newMenu;  
    }

    BufferedReader fileReader;
}
