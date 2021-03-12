package program_4_5.activity;

import program_4_5.activity.exercise.Cardio;
import program_4_5.activity.exercise.Exercise;
import program_4_5.activity.exercise.HIIT;
import program_4_5.activity.exercise.Yoga;
import program_4_5.activity.garden.Indoor;
import program_4_5.activity.garden.Outdoor;
import program_4_5.activity.garden.Research;
import program_4_5.adt.ADT;
import program_4_5.utils.Utils;

import static program_4_5.adt.ADT.LinkedList.getRoot;

public class Activity {
    /**
     * This holds onto a Garden or Exercise Activity
     */
    protected Activity anActivity;

    /**
     * Default class constructor
     */
    public Activity() {
        this.anActivity = null;
    }

    /**
     * Default class Copy constructor
     * @param copyActivity consists of two Strings
     */
    public Activity(Activity copyActivity) {
        this.anActivity = copyActivity.anActivity;
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

        /* Get user input via custom Utils class */
        int choice = Utils.getChoice();

        /* Choice 1 = Add Exercise: Cardio, HIIT, or Yoga */
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

            /*
             * The if statements below allow us to decide what type of activity you want
             * to enter. This is done via casting. The Object being used is Activity, and
             * its derived classes, Exercise and Garden are pure abstract classes. Each of
             * those have three derived classes that we are casting to the Activities object.
             */

            /* New Cardio Exercise Activity */
            if (eChoice == 1) {
                Activity newCardio = new Cardio();
                newCardio.addActivity();
                this.anActivity = (Exercise) newCardio;
            }

            /* New HIIT Exercise Activity */
            if (eChoice == 2) {
                Activity newHIIT = new HIIT();
                newHIIT.addActivity();
                this.anActivity = (Exercise) newHIIT;
            }

            /* New Yoga Exercise Activity */
            if (eChoice == 3) {
                Activity newYoga = new Yoga();
                newYoga.addActivity();
                this.anActivity = (Exercise) newYoga;
            }
        }

        /* Choice 2 = New Garden: Indoor, Outdoor, or Research */
        if (choice == 2) {
            System.out.println("\nWhat type of Gardening activity would you like to add?\n");
            System.out.println("1. Outdoor\n2. Indoor\n3. Research\n");

            /* Get user choice via custom Utils class */
            int gChoice = Utils.getChoice();

            /*
             *  The line below is to swallow the EOL from the Utils.getChoice() function.
             *  The *.nextInt(); causes the next called *.nextLine() to skip the first
             *  input because the *.nextInt(); ignores and leaves the EOL in the buffer,
             *  at least from how I understand it after searching and debugging.
             */
            Utils.userInput.nextLine();

            /* Cast new Outdoor Garden Activity */
            if (gChoice == 1) {
                Activity newOutdoor = new Outdoor();
                newOutdoor.addActivity();
                this.anActivity = newOutdoor;
            }

            /* Cast new Indoor Garden Activity */
            if (gChoice == 2) {
                Activity newIndoor = new Indoor();
                newIndoor.addActivity();
                this.anActivity = newIndoor;
            }

            /* Cast new Research Garden Activity */
            if (gChoice == 3) {
                Activity newResearch = new Research();
                newResearch.addActivity();
                this.anActivity = newResearch;
            }
        }

        return 1;
    }

    /*
     * Search for an activity in the list
     */
    public void searchActivity() {

    }

    /*
     * Display an activity from the list
     */
    public void displayActivity() {
        if (getRoot() == null) {
            System.out.println("\nEnd of the list.\n");
            return;
        }
        displayActivity(ADT.LinkedList.getRoot().getNext());
    }

    private void displayActivity(ADT.Node root) {
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
