package program_4_5.activity.garden;

import program_4_5.adt.ADT;

public class Research extends Garden {
    public Research() {
        super();
    }

    @Override
    public int addActivity() {
        ADT.LinkedList.addNode();
        return 1;
    }

    @Override
    public void searchActivity() {

    }

    @Override
    public void displayActivity() {

    }
}
