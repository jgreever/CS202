/*
 * Justin Greever
 * CS202 - Program 5
 * 3/17/2021
 *
 * This is the Activity class file. It extends the UserIO class. When this class object is created,
 * it will allow the user to choose the type of activity to add to the list. The functions are very
 * bare, as the derived classes handle most of the work needed to get the job done.
 *
 * Derived classes: Exercise, Relax
 *
 */
package ninja.introverted.Activities;

import ninja.introverted.ADT.AVLTree;
import ninja.introverted.Utils.UserIO;

public class Activity extends UserIO {
    Activity anActivity;

    public int compareActs(Activity activityOne, Activity activityTwo) {
        if (activityOne == null) return -1;
        if (activityTwo == null) return 1;
        int results = ExerciseImpl.Yoga.Yoga.compareActivities(activityOne.anActivity.toString(), activityTwo.anActivity.toString());
        return results;
    }

    public void addActivity() {
        /* What type of activity will we do? Let's store it here */
        int activityType = 0;
        activityType = whatTypeOfActivity();
        if(activityType == 1) {
            anActivity = new ExerciseImpl.Yoga();
            anActivity.addActivity();
        }

        if(activityType == 2) {
            anActivity = new ExerciseImpl.Running();
            anActivity.addActivity();
        }

        if(activityType == 3) {
            anActivity = new ExerciseImpl.Weights();
            anActivity.addActivity();
        }

        if(activityType == 4) {
            anActivity = new RelaxImpl.Napping();
            anActivity.addActivity();
        }

        if(activityType == 5) {
            anActivity = new RelaxImpl.Reading();
            anActivity.addActivity();
        }

        if(activityType == 6) {
            anActivity = new RelaxImpl.Writing();
            anActivity.addActivity();
        }

    }

    public void displayActivity() {
        System.out.println("\nActivity Data: ");
        anActivity.displayActivity();
    }

    public void searchActivity(String toSearch) {
        System.out.println("\nSearching...");
        anActivity.searchActivity(toSearch);

    }
}
