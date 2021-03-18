/*
 * Justin Greever
 * CS202 - Program 5
 * 3/17/2021
 *
 * This is the AVLTree class. It contains the AVLNode sub-class within it. This is based
 * on a balanced AVL Tree.
 *
 * The AVLNode contains pointers to left and right, then a pointer to an Activity object,
 * then an int for the height of the tree.
 *
 */
package ninja.introverted.ADT;

import ninja.introverted.Activities.Activity;
import ninja.introverted.Utils.UserIO;

class AVLNode {
    AVLNode left, right;
    Activity actData;
    int height;

    public AVLNode(Activity toCopy) {
        left = null;
        right = null;
        actData = toCopy;
        height = 0;
    }
}

public class AVLTree {
    private AVLNode root;
    private Activity anActivity;

    /* Check if the list is empty */
    public boolean isEmpty() {
        return root == null;
    }

    /* Empty the list completely */
    public void emptyTheList() {
        root = null;
    }

    /* This allows us to get the height of the tree */
    private int getHeight(AVLNode getHeight) {
        return getHeight == null ? -1 : getHeight.height;
    }

    /* This allows us to determine the max value between two int variables */
    private int getMax(int leftMax, int rightMax) {
        return leftMax > rightMax ? leftMax : rightMax;
    }

    /* This allows us to publicly call the countAllNodes function. It will
     * return the amount of nodes in the tree.
     */
    public int countAllNodes() {
        return countAllNodes(root);
    }

    /* This is the private function to count all nodes */
    private int countAllNodes(AVLNode toCount) {
        if (toCount == null) return 0; //nothing to count, hooray!
        else {
            int count = 1;
            count += countAllNodes(toCount.left);
            count += countAllNodes(toCount.right);
            return count;
        }
    }

    /* public wrapper for inserting data into the AVL Tree */
    public void insert() {
        root = insert(root, anActivity);
    }

    /* If we need to rotate our sub-tree to the left, this function will take care of that */
    private AVLNode rotateLeft(AVLNode toRotate) {
        AVLNode temp = toRotate.left;
        toRotate.left = temp.right;
        temp.right = toRotate;
        toRotate.height = getMax(getHeight(toRotate.left), getHeight(toRotate.right)) + 1;
        temp.height = getMax(getHeight(temp.left), getHeight(temp.right)) + 1;
        return temp;
    }

    /* this will rotate a tree to the right to maintain balance */
    private AVLNode rotateRight(AVLNode toRotate) {
        AVLNode temp = toRotate.right;
        toRotate.right = temp.left;
        temp.left = toRotate;
        toRotate.height = getMax(getHeight(toRotate.left), getHeight(toRotate.right)) + 1;
        temp.height = getMax(getHeight(temp.left), getHeight(temp.right)) + 1;
        return temp;
    }

    /* This allows us to perform a full rotation (double rotation) to balance a tree */
    private AVLNode doubleRotateLeft(AVLNode toRotate) {
        toRotate.left = rotateRight(toRotate.left);
        return rotateLeft(toRotate);
    }

    /* The same as above, but does a full rotation to the right */
    private AVLNode doubleRotateRight(AVLNode toRotate) {
        toRotate.right = rotateLeft(toRotate.right);
        return rotateRight(toRotate);
    }

    /* This is our insert function. You hand it an empty AVLNode and it fills it
     * and passes it back to the calling function.
     */
    private AVLNode insert(AVLNode addTo, Activity anActivity) {
        if (addTo == null)
            addTo = new AVLNode(anActivity);
        else if (anActivity.compareActs(anActivity, addTo.actData) < 0) {
            addTo.left = insert(addTo.left, anActivity);
            if (getHeight(addTo.left) - getHeight(addTo.right) == 2) {
                if (anActivity.compareActs(anActivity, addTo.left.actData) < 0) {
                    addTo = rotateLeft(addTo);
                } else
                    addTo = rotateRight(addTo);
            }
        } else if (anActivity.compareActs(anActivity, addTo.actData) > 0) {
            addTo.right = insert(addTo.right, anActivity);
            if (getHeight(addTo.right) - getHeight(addTo.left) == 2) {
                if (anActivity.compareActs(anActivity, addTo.actData) > 0) {
                    addTo = rotateRight(addTo);
                } else
                    addTo = rotateLeft(addTo);
            }
        } else
            ; //nothing to do, they are the same entry
        addTo.height = getMax(getHeight(addTo.left), getHeight(addTo.right)) + 1;
        return addTo;
    }

    public void add() {
        anActivity = new Activity();
        anActivity.addActivity();

        if (root == null) {
            root = new AVLNode(anActivity);
            insert(root, anActivity);
        } else insert(root, anActivity);

    }

    public void display() {
        display(root);
    }

    public void display(AVLNode toDisplay) {
        if (toDisplay != null) {
            System.out.println("\nThe list contains the following entries: ");
            toDisplay.actData.displayActivity();
            display(toDisplay.left);
            display(toDisplay.right);
        }
    }

    public int search() {
        System.out.println("\nPlease enter the activity name to search for: ");
        String toSearch = UserIO.getInput();
        search(root, toSearch);
        return 1;
    }

    private void search(AVLNode search, String toSearch) {
        if (search != null) {
            search.actData.searchActivity(toSearch);
            search(search.left, toSearch);
            search(search.right, toSearch);
        }
    }
}


