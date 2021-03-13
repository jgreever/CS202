/*
 * Justin Greever
 * CS202 - Program 4
 * 3/5/2021
 *
 * This is the ADT class. This contains all the information for our LLL, ARR, and 2-3 Tree
 * (but won't be fully functional until Program 5).
 *
 * The LLL will be the basic ADT for the 6 derived classes (Cardio, HIIT, Yoga, Indoor,
 * Outdoor, and Research). One of the three Exercise derived classes (Cardio, HIIT, or
 * Yoga) will use the ARR, most likely it will be the HIIT class (High-Intensity Interval
 * Training), so the user can track multiple exercise types and times.
 *
 */
package program_4_5.adt;

import program_4_5.utils.Utils;

public class ADT {
    /**
     * This is the ARR class. It will be used for the HIIT derived class.
     * It will be an array of head pointers to a LLL that will hold onto
     * information about workouts/times/etc (so you can plan an entire gym
     * session)
     */
    public static class ARR extends ADT {
        private static arrNode[] head;

        public static class arrNode extends ARR {
            private String hiitRoutine;
            private arrNode next;

            public arrNode() {
                hiitRoutine = "";
                next = null;
            }

            public arrNode getNext() {
                return this.next;
            }

            public void setNext(arrNode isNext) {
                this.next = isNext;
            }
        }
    }


    /*
     * This is the Linked List class. This will take care of managing any data
     * that we store in a LLL. The basic functions are add/edit/search/display/delete
     */
    public static class LinkedList extends ADT {
        /* Our root node pointer for traversal */
        private static Node root;

        /* Default LinkedList class constructor */
        private LinkedList() {
            root = null;
        }

        /**
         * This is our addNode function that will take grab userInput via the Utils class
         * and create a new Node to be added to the LLL/ARR.
         *
         * @return a 0 or 1
         */
        public static int addNode() {
            if (root == null)
                root = new Node();
            Node temp = new Node();
            System.out.println("\nPlease enter the name of the Activity: ");
            temp.itemName = Utils.getInput();
            System.out.println("\nPlease enter the Activity information: ");
            temp.itemInfo = Utils.getInput();
            if (addNode(root, temp) == 1) {
                System.out.println("\nSuccess! Activity added.");
                return 1;
            } else {
                System.out.println("\nFailed to add... Try again.");
                return 0;
            }
        }

        public static int addHIITNode() {
            if (root == null) {
                root = new Node();
                root.hiitList = new ARR.arrNode();
            }
            Node temp = new Node();
            System.out.println("\nPlease enter the HIIT Exercise: ");
            temp.itemName = Utils.getInput();
            System.out.println("\nPlease enter amount of repetitions: ");
            temp.itemInfo = Utils.getInput();
            boolean isDone = false;
            while(!isDone) {
                System.out.println("\nPlease enter the day(s) for this Exercise: ");
                System.out.println("(0) Sunday, (1) Monday, (2) Tuesday, (3) Wednesday, " +
                        "(4) Thursday, (5) Friday, (6) Saturday");
                int whatDay = Utils.getChoice();
                Utils.userInput.nextLine();
                System.out.println("\n");
                System.out.println("\nEnter the time to start the HIIT Exercise: ");
                temp.hiitList.hiitRoutine = Utils.getInput();
                if (root.hiitList.hiitRoutine == null) {
                    root.hiitList = temp.hiitList;
                } else {
                    root.hiitList.setNext(temp.hiitList);
                    //.hiitRoutine = temp.hiitList[whatDay].hiitRoutine;
                }
                System.out.println("\nEnter another Day/Time? (1) for Yes, (2) for No: ");
                int choice = Utils.getChoice();
                Utils.userInput.nextLine();
                isDone = choice != 1;
            }
            if (addNode(root, temp) == 1) {
                System.out.println("\nSuccess! Activity added.");
                return 1;
            } else {
                System.out.println("\nFailed to add... Try again.");
                return 0;
            }
        }

        private static int addNode(Node root, Node toAdd) {
            if (root == null) {
                root = new Node(toAdd);
                return 1;
            }
            if (root.next == null) {
                root.setNext(toAdd);
                return 1;
            } else {
                addNode(root.next, toAdd);
            }
            return 1;
        }

        /* Get our root node and return it */
        public static Node getRoot() {
            return root;
        }

        /* Set our root node */
        public static void setRoot(Node root) {
            LinkedList.root = root;
        }
    }

    /**
     * This is our Node class. It holds two strings and a next pointer. This is a basic
     * setup for a simple LLL and ARR. It can be adapted or a new class added for things
     * like BST/Tables/etc down the road.
     */
    public static class Node extends ADT {
        /* These can be adjusted to fit the program, but two strings and a next pointer for now */
        private String itemName;
        private String itemInfo;
        private ARR.arrNode hiitList; // = new ARR.arrNode[6];
        private Node next;

        /* Default Node class constructor */
        public Node() {
            this.itemName = "";
            this.itemInfo = "";
            this.hiitList = new ARR.arrNode();
            this.next = null;
        }

        /* Default Node class copy constructor w/o next pointer */
        public Node(String iName, String iInfo, ARR.arrNode ahiitList) {
            this.itemName = iName;
            this.itemInfo = iInfo;
            this.hiitList = ahiitList;
            this.next = null;
        }

        /* Default Node class copy constructor w/next pointer */
        public Node(String iName, String iInfo, ARR.arrNode ahittList, Node addNext) {
            this.itemName = iName;
            this.itemInfo = iInfo;
            this.hiitList = ahittList;
            this.next = addNext;
        }

        /* Default Node class copy constructor using Object */
        public Node(Node toCopy) {
            this.itemName = toCopy.itemName;
            this.itemInfo = toCopy.itemInfo;
            this.hiitList = toCopy.hiitList;
            this.next = toCopy.next;
        }

        /*
         * This is our Getters/Setters section. The Node class needs them in order
         * to store/retrieve data and set/get the next pointer.
         */

        /**
         * This will grab all the data from the ARR and return it to the calling
         * function or display the data to the user.
         *
         * @return pass String data concatenated from ARR
         */
        public String getArrData() {
            return ("\nActivity Name: " + this.itemName +
                    "\nActivity Information: " + this.itemInfo +
                    "\nHIIT Info: " + this.hiitList.hiitRoutine);
        }

        /**
         * This is our getter for getting data from the object. It will pass back
         * the String data concatenated for viewing.
         *
         * @return pass back the String data concatenated
         */
        public String getData() {
            if (this.hiitList.hiitRoutine != "")
                return getArrData();
            else
                return ("\nActivity Name: " + this.itemName +
                        "\nActivity Information: " + this.itemInfo);
        }

        /**
         * This is our setter for setting data. It will take two string objects
         * passed into it and store them in the current Node.
         *
         * @param iName the Activity Name
         * @param iInfo the Activity Information
         */
        public void setData(String iName, String iInfo) {
            this.itemName = iName;
            this.itemInfo = iInfo;
        }

        /**
         * This is our getter for getting the next pointer and returning it to the
         * calling function. This is needed for proper traversal.
         *
         * @return pass this.next back
         */
        public Node getNext() {
            return this.next;
        }

        /**
         * This is our setter for setting the next pointer. It will take the Node that
         * is passed in, and set it as the current Nodes next pointer.
         *
         * @param upNext our next pointer
         */
        public void setNext(Node upNext) {
            this.next = upNext;
        }
    }
}

