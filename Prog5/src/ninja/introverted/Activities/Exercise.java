/*
 * Justin Greever
 * CS202 - Program 5
 * 3/17/2021
 *
 * This file is the Exercise Abstract Base Class. It is basically an Interface
 * for the 3 derived classes from it (Running, Weights, Yoga).
 *
 * The derived classes handle all their data members and management of them.
 * This class extends Activity (Is-A)
 *
 */
package ninja.introverted.Activities;

public abstract class Exercise extends Activity {

    public abstract void addActivity();
    public abstract void displayActivity();
    public abstract void searchActivity(String toSearch);
}
