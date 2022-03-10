public class Restuarants {
    
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

    public int compare(menuNode comp) {
        return this.data.compare(comp.data);
    }

    public boolean compare(String name) {
        return this.data.compare(name);
    }

    protected Menu data;
    protected menuNode left;
    protected menuNode right;
} 