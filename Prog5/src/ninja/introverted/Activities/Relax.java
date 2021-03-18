/*
 * Justin Greever
 * CS202 - Program 5
 * 3/17/2021
 *
 * This is the Relax class. It is pure abstract (basically an Interface). It pushes down any
 * questions to its derived classes: Napping, Reading, Writing
 *
 * This class "Is-A" Activity
 *
 */
package ninja.introverted.Activities;

public abstract class Relax extends Activity {

    public abstract void addActivity();
    public abstract void displayActivity();
    public abstract void searchActivity(String toSearch);
}
