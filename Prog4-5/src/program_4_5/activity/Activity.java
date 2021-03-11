package program_4_5.activity;

import program_4_5.activity.exercise.Cardio;
import program_4_5.activity.exercise.Exercise;
import program_4_5.activity.exercise.HIIT;
import program_4_5.activity.exercise.Yoga;
import program_4_5.activity.garden.Garden;
import program_4_5.activity.garden.Indoor;
import program_4_5.activity.garden.Outdoor;
import program_4_5.activity.garden.Research;
import program_4_5.adt.ADT;
import program_4_5.utils.Utils;

import static program_4_5.adt.ADT.LinkedList.getRoot;

public class Activity {
    /**
     * Set our array size to 2, 0 = newGarden, 1 = newExercise. These values are
     * not set in stone, and may be changed to allow more array values later.
     */
    final int ARRAY_SIZE = 2;
    protected Garden newGarden;
    protected Exercise newExercise;

    /**
     * Default class constructor
     */
    public Activity() {
        this.newGarden = null;
        this.newExercise = null;
    }

    /**
     * Default class Copy constructor
     * @param anActivity consists of two Strings
     */
    public Activity(Activity anActivity) {
        this.newGarden = anActivity.newGarden;
        this.newExercise = anActivity.newExercise;
    }

    /*
     * Below are the functions that are pushed down through the hierarchy.
     * These are the basic functions: add, edit, search, and display.
     */

    /**
     * Add an activity to the list
     * @return a 0 or 1
     */
    public int addActivity() {
        System.out.println("\nWhat type of Activity would you like to add?\n");
        System.out.println("1. Exercise\n2. Gardening\n");
        int choice = Utils.getChoice();
        if (choice == 1) {
            System.out.println("\nWhat type of Exercise would you like to add?\n");
            System.out.println("1. Cardio\n2. HIIT\n3. Yoga\n");
            int eChoice = Utils.getChoice();

            /*
             *  The line below is to swallow the EOL from the Utils.getChoice() function.
             *  The *.nextInt(); causes the next called *.nextLine() to skip the first
             *  input because the *.nextInt(); ignores and leaves the EOL in the buffer,
             *  at least from how I understand it after searching and debugging.
             */
            Utils.userInput.nextLine();
            if (eChoice == 1) {
                Exercise newCardio = new Cardio();
                newCardio.addActivity();
                this.newExercise = newCardio;
            }
            if (eChoice == 2) {
                Exercise newHIIT = new HIIT();
                newHIIT.addActivity();
                this.newExercise = newHIIT;
            }
            if (eChoice == 3) {
                Exercise newYoga = new Yoga();
                newYoga.addActivity();
                this.newExercise = newYoga;
            }
        }

        if (choice == 2) {
            System.out.println("\nWhat type of Gardening activity would you like to add?\n");
            System.out.println("1. Outdoor\n2. Indoor\n3. Research\n");
            int gChoice = Utils.getChoice();

            /*
             *  The line below is to swallow the EOL from the Utils.getChoice() function.
             *  The *.nextInt(); causes the next called *.nextLine() to skip the first
             *  input because the *.nextInt(); ignores and leaves the EOL in the buffer,
             *  at least from how I understand it after searching and debugging.
             */
            Utils.userInput.nextLine();
            if (gChoice == 1) {
                Garden newOutdoor = new Outdoor();
                newOutdoor.addActivity();
                this.newGarden = newOutdoor;
            }
            if (gChoice == 2) {
                Garden newIndoor = new Indoor();
                newIndoor.addActivity();
                this.newGarden = newIndoor;
            }
            if (gChoice == 3) {
                Garden newResearch = new Research();
                newResearch.addActivity();
                this.newGarden = newResearch;
            }
        }

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
        if (getRoot() == null) {
            System.out.println("\nEnd of the list.\n");
        }
        displayActivity(ADT.LinkedList.getRoot().getNext());
    }

    public void displayActivity(ADT.Node root) {
        if (root == null)
            return;
        /*
         * I have it set to start out printing the information from
         * root.next first, as the root pointer is always null but
         * it populates the next pointer perfectly fine. I had this
         * issue in C++ as well.
         */
        System.out.println(root.getData());
        displayActivity(root.getNext());
    }
}
