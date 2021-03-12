package program_4_5.activity.exercise;

import program_4_5.adt.ADT;
import program_4_5.utils.Utils;

public class HIIT extends Exercise {

    public HIIT() {
        super();
    }

    public HIIT(HIIT toCopy) {
        super();
    }

    @Override /* itemName = HIIT Exercise, itemInfo = HIIT Exercise Length */
    public int addActivity() {
        ADT.LinkedList.addHIITNode();
        return 1;
    }

    public void searchActivity() {

    }

    public void displayActivity() {

    }
}
