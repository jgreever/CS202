package program_4_5;

import adt.ADT;

public class Activity {
    /**
     * Set our array size to 2, 0 = Garden, 1 = Exercise. These values are
     * not set in stone, and may be changed to allow more array values later.
     */
    final int ARRAY_SIZE = 2;
    protected ADT.Node root;
    protected Garden newGarden;
    protected Exercise newExercise;

    /**
     * Default class constructor
     */
    public Activity() {
        this.root = null;
        this.newGarden = null;
        this.newExercise = null;
    }

    /**
     * Default class Copy constructor
     * @param anActivity
     */
    public Activity(Activity anActivity) {
        this.root = anActivity.root;
        this.newGarden = anActivity.newGarden;
        this.newExercise = anActivity.newExercise;
    }

    /**
     * Below are the functions that are pushed down through the hierarchy.
     * These are the basic functions: add, edit, search, and display.
     */

    /**
     * Add an activity to the list
     * @return
     */
    public int addActivity() {

        return 1;
    }

    /**
     * Edit an activity in the list
     * @return
     */
    public int editActivity() {

        return 1;
    }

    /**
     * Search for an activity in the list
     */
    public void searchActivity() {

    }

    /**
     * Display an activity from the list
     */
    public void displayActivity() {

    }
}
