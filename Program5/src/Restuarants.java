public class Restuarants {
    
    public Restuarants() {
        root = null;
    }

    public void insertMenu(Menu data) {
        if (data == null) return;
        this.root = insertMenu(this.root, new menuNode(data));
    }

    public menuNode insertMenu(menuNode root, menuNode inserting) {
        if (root == null) {
            root = inserting;
            return root;
        }
        
        int comp = root.compareTree(inserting);
        if (comp == 1 || comp == 0) root.setRight(insertMenu(root.getRight(), inserting));
        else root.setLeft(insertMenu(root.getLeft(), inserting));
        return root;
    }

    public menuNode retrieve(String cuisine) {
        if (cuisine == null) return null;
        return retrieve(this.root, cuisine);
    }

    public menuNode retrieve(menuNode root, String cuisine) {
        if (root == null) return null;
        int comp = root.compareTree(cuisine);
        if (comp == 0) return root;
        else if (comp == 1) retrieve(root.getRight(), cuisine);
        else retrieve(root.getLeft(), cuisine);
        return root;
    }

    public Menu retrieveName(String name) {
        if (name == null) return null;
        return retrieveName(this.root, name);
    }

    private Menu retrieveName(menuNode root, String name) {
        if (root == null) return null;
        if (root.getData().compare(name)) return root.getData();
        Menu left = retrieveName(root.getLeft(), name);
        Menu right = retrieveName(root.getRight(), name);
        if (left != null) return left;
        else if (right != null) return right;
        return null;
    }

    public void display () {
        if (this.root == null) return;
        display(this.root);
    }

    public void display(menuNode root) {
        if (root == null) return;
        display(root.getLeft());
        root.display();
        display(root.getRight());
    }

    public void delete(String cuisine) {
        if (cuisine == null) return;
        menuNode deleting = retrieve(cuisine);
        if (deleting == null) return;
        delete(deleting);
    }

    public void delete(menuNode deleting) {
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

    public menuNode inOrderSuccessor(menuNode root) {
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

class menuNode {
    public menuNode() {
        this.data = null;
        this.left = null;
        this.right = null;
    }

    public menuNode(Menu data) {
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

    public int compareTree(menuNode comp) {
        return this.data.compareTree(comp.data);
    }

    public int compareTree(String cuisine) {
        return this.data.compareTree(cuisine);
    }

    public boolean compareName(String name) {
        return this.data.compare(name);
    }

    public void display() {
        this.data.display();
    }

    protected Menu data;
    protected menuNode left;
    protected menuNode right;
} 