package program_4_5.activity.exercise;

public class Cardio extends Exercise {
    public Cardio() {
        super();
    }

    @Override
    public int addActivity() {
        ll.addNode();
        return 1;
    }
}
