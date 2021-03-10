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
package program_4_5;

public class Indoor extends Garden {
    private String indoorName;
    private String indoorWork;

    /**
     * Default class constructor
     */
    Indoor() {
        this.indoorName = null;
        this.indoorWork = null;
    }

    /**
     * Default class copy constructor
     * @param indoorProject
     */
    Indoor(Indoor indoorProject) {
        this.indoorName = indoorProject.indoorName;
        this.indoorWork = indoorProject.indoorWork;
    }

    /**
     * Add an activity
     * @return
     */
    @Override
    public int addActivity() {
        return 0;
    }

    /**
     * Edit an Activity
     * @return
     */
    @Override
    public int editActivity() {
        return 0;
    }

    /**
     * Search for an Activity
     */
    @Override
    public void searchActivity() {

    }

    /**
     * Display an activity
     */
    @Override
    public void displayActivity() {

    }
}
