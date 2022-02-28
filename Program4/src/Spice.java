
public class Spice extends Item {
    Spice() {
        this.spice = 0;
    }
    
    Spice(int spice) {
        this.spice = spice;
        if (this.spice > 10) this.spice = 10;
    }

    public void setSpice(int spice) {
        this.spice = spice;
        if (this.spice > 10) this.spice = 10;
    }

    //data members
    protected int spice;
}
