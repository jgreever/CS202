package program_4_5.activity.garden;

public class Outdoor extends Garden {
    public Outdoor() {
        super();
    }

    @Override
    public int addActivity() {
        ll.addNode();
        return 1;
    }
}
