/* Omar Nassar
 * Portland State University CS202
 * March 9, 2022
 * Binary Search tree to store menus
 */

public class Restuarants {
    
    public Restuarants() {//default constructor
        root = null;
    }

    public void insertMenu(Menu data) {//wrapper function for inserting
        if (data == null) return;
        this.root = insertMenu(this.root, new menuNode(data));
    }

    private static menuNode insertMenu(menuNode root, menuNode inserting) {//recursive insert
        if (root == null) {
            root = inserting;
            return root;
        }
        
        int comp = root.compareTree(inserting);
        if (comp == 1 || comp == 0) root.setRight(insertMenu(root.getRight(), inserting));
        else root.setLeft(insertMenu(root.getLeft(), inserting));
        return root;
    }

    public menuNode retrieve(String cuisine) {//wrapper for retrieval
        if (cuisine == null) return null;
        return retrieve(this.root, cuisine);
    }

    private static menuNode retrieve(menuNode root, String cuisine) {//recursive retrieve
        if (root == null) return null;
        int comp = root.compareTree(cuisine);
        if (comp == 0) return root;
        else if (comp == 1) root = retrieve(root.getRight(), cuisine);
        else root = retrieve(root.getLeft(), cuisine);
        return root;
    }

    public Menu retrieveName(String name) {//wrapper for retrieve by name
        if (name == null) return null;
        return retrieveName(this.root, name);
    }

    private static Menu retrieveName(menuNode root, String name) {//recursive retrieve by name
        if (root == null) return null;
        if (root.getData().compare(name)) return root.getData();
        Menu left = retrieveName(root.getLeft(), name);
        Menu right = retrieveName(root.getRight(), name);
        if (left != null) return left;
        else if (right != null) return right;
        return null;
    }

    public void display () {//wrapper for display
        if (this.root == null) return;
        display(this.root);
    }

    private static void display(menuNode root) {//recursive display
        if (root == null) return;
        display(root.getLeft());
        System.out.println();
        root.display();
        display(root.getRight());
    }


    public void delete(String cuisine) {//wrapper for deleting
        if (cuisine == null) return;
        menuNode deleting = retrieve(cuisine);
        if (deleting == null) return;
        delete(deleting);
    }

    private void delete(menuNode deleting) {//recursive delete
        menuNode left = deleting.getLeft();
        menuNode right = deleting.getRight();
        if (left == null && right == null) deleting = null;
        else if (right == null) deleting = left;
        else if (left == null) deleting = right;
        else {
            menuNode temp = inOrderSuccessor(deleting.getRight());
            temp.setRight(deleting.getRight());
            temp.setLeft(deleting.getLeft());
            deleting = temp;
        }
    }

    private menuNode inOrderSuccessor(menuNode root) {
        menuNode left = root.getLeft();
        menuNode right = root.getRight();
        if (left == null) {
            menuNode temp = root;

            if (right != null) root = right;
            else root = null;

            temp.setRight(null);
            return temp;
        }
        return inOrderSuccessor(root.getLeft());
    }

    protected menuNode root;
}

class menuNode {//node class for BST
    public menuNode() {//default constructor
        this.data = null;
        this.left = null;
        this.right = null;
    }

    public menuNode(Menu data) {//constructor with args
        this.data = data;
        this.left = null;
        this.right = null;
    }

    public Menu getData() {
        return this.data;
    }

    public menuNode getLeft() {
        return this.left;
    }

    public void setLeft(menuNode left) {
        this.left = left;
    }

    public menuNode getRight() {
        return this.right;
    }

    public void setRight(menuNode right) {
        this.right = right;
    }

    public int compareTree(menuNode comp) {//comparing to another node
        return this.data.compareTree(comp.data);
    }

    public int compareTree(String cuisine) {//comparing node data with string cuisine
        return this.data.compareTree(cuisine);
    }

    public boolean compareName(String name) {//comparing node data with string name
        return this.data.compare(name);
    }

    public void display() {//displaying
        this.data.display();
    }

    protected Menu data;
    protected menuNode left;
    protected menuNode right;
} 