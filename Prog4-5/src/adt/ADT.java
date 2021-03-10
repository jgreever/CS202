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
package adt;

public class ADT {

    public static class Node {
        private String itemName;
        private String itemInfo;
        private Node next;

        public Node() {
            this.itemName = null;
            this.itemInfo = null;
        }

        public Node(String iName, String iInfo) {
            this.itemName = iName;
            this.itemInfo = iInfo;
        }
    }

}
