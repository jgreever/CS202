package program_4_5.activity.garden;

public class Research extends Garden {
    public Research() {
        super();
    }

    @Override
    public int addActivity() {
        ll.addNode();
        return 1;
    }
}
