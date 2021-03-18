package program_4_5.activity;

import program_4_5.activity.exercise.Cardio;
import program_4_5.activity.exercise.Exercise;
import program_4_5.activity.exercise.HIIT;
import program_4_5.activity.exercise.Yoga;
import program_4_5.activity.garden.Indoor;
import program_4_5.activity.garden.Outdoor;
import program_4_5.activity.garden.Research;
import program_4_5.adt.ADT;
import program_4_5.adt.ADT.LinkedList;
import program_4_5.utils.Utils;

@SuppressWarnings("EmptyMethod")
public class Activity {
    private LinkedList root = new LinkedList();

    /**
     * Default class constructor
     */
    public Activity() {
        root = null;
    }

    /*
     * Below are the functions that are pushed down through the hierarchy.
     * These are the basic functions: add, edit, search, and display.
     */

    /**
     * Add an activity to the list
     * @return a 0 or 1
     */
    @SuppressWarnings("UnusedReturnValue")
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
                anActivity = new Cardio();
                anActivity.addActivity();
            }

            /* New HIIT Exercise Activity */
            if (eChoice == 2) {
                Exercise newHIIT = new HIIT();
                newHIIT.addActivity();
            }

            /* New Yoga Exercise Activity */
            if (eChoice == 3) {
                Exercise newYoga = new Yoga();
                newYoga.addActivity();
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
            }

            /* Cast new Indoor Garden Activity */
            if (gChoice == 2) {
                Activity newIndoor = new Indoor();
                newIndoor.addActivity();
            }

            /* Cast new Research Garden Activity */
            if (gChoice == 3) {
                Activity newResearch = new Research();
                newResearch.addActivity();
            }
            return 1;
        }
        return 0;
    }


    public int addNode() {
        if (root == null)
            this.root = new LinkedList();
        LinkedList temp = new LinkedList();
        System.out.println("\nPlease enter the name of the Activity: ");
        temp.itemName = Utils.getInput();
        System.out.println("\nPlease enter the Activity information: ");
        temp.itemInfo = Utils.getInput();
        if (addNode(this.root, temp) == 1) {
            System.out.println("\nSuccess! Activity added.");
            return 1;
        } else {
            System.out.println("\nFailed to add... Try again.");
            return 0;
        }
    }

    private int addNode(Node current, Node toAdd) {
        if (this.root == null) {
            this.root = new Node(toAdd);
            return 1;
        }
        if (current.getNext() == null) {
            current.setNext(toAdd);
            return 1;
        } else {
            addNode(current.getNext(), toAdd);
        }
        return 0;
    }

    /* Get our root node and return it */
    public LinkedList.Node getRoot() {
        return this.root;
    }

    /* Set our root node */
    public void setRoot(LinkedList.Node toSet) {
        this.root = toSet;
    }
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
        if (ll.getRoot() == null) {
            System.out.println("\nEnd of the list.\n");
            return;
        }
        displayActivity(ll.getRoot().getNext());
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
