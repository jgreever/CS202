/*
 * Justin Greever
 * CS202 - Program 4
 * 3/5/2021
 *
 * This is the Indoor derived class of the Garden class. This class
 * holds onto the name of the indoor gardening activity, and what type
 * of work needs to be done to complete the activity.
 *
 */
package program_4_5.activity.garden;

public class Indoor extends Garden {

    /**
     * Default class constructor
     */
    public Indoor() {
        super();
    }

    /**
     * Add an activity
     * @return a 0 or 1
     */
    @Override
    public int addActivity() {
        ll.addNode();
        return 1;
    }
}
