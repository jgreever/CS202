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
    /*
     * This is going to be the best AVL tree out there. It will have a balance factor,
     * height check to ensure the tree hasn't grown too large, and (hopefully) the ability
     * to make copies of trees automagically!
     */
    public class AVLTree  extends ADT {

    }


    /*
     * This is the Linked List class. This will take care of managing any data
     * that we store in a LLL. The basic functions are add/edit/search/display/delete
     */
    @SuppressWarnings("UnusedReturnValue")
    public static class LinkedList extends ADT {

        /* Default LinkedList class constructor */
        public LinkedList() {
        }

        /**
         * This is our addNode function that will take grab userInput via the Utils class
         * and create a new Node to be added to the LLL/ARR.
         *
         * @return a 0 or 1
         */
/*        public int addNode() {
            if (root == null)
                this.root = new Node();
            Node temp = new Node();
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

        *//* Get our root node and return it *//*
        public Node getRoot() {
            return this.root;
        }

        *//* Set our root node *//*
        public void setRoot(Node toSet) {
            this.root = toSet;
        }
    }*/

    /**
     * This is our Node class. It holds two strings and a next pointer. This is a basic
     * setup for a simple LLL and ARR. It can be adapted or a new class added for things
     * like BST/Tables/etc down the road.
     */
    public static class Node extends ADT {
        /* These can be adjusted to fit the program, but two strings and a next pointer for now */
        private String itemName;
        private String itemInfo;
        private Node next;

        /* Default Node class constructor */
        public Node() {
            this.itemName = "";
            this.itemInfo = "";
            this.next = null;
        }

        /* Default Node class copy constructor w/o next pointer */
        public Node(String iName, String iInfo) {
            this.itemName = iName;
            this.itemInfo = iInfo;
            this.next = null;
        }

        /* Default Node class copy constructor w/next pointer */
        public Node(String iName, String iInfo, Node addNext) {
            this.itemName = iName;
            this.itemInfo = iInfo;
            this.next = addNext;
        }

        /* Default Node class copy constructor using Object */
        public Node(Node toCopy) {
            this.itemName = toCopy.itemName;
            this.itemInfo = toCopy.itemInfo;
            this.next = toCopy.next;
        }

        /*
         * This is our Getters/Setters section. The Node class needs them in order
         * to store/retrieve data and set/get the next pointer.
         */

        /**
         * This is our getter for getting data from the object. It will pass back
         * the String data concatenated for viewing.
         *
         * @return pass back the String data concatenated
         */
        public String getData() {
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

