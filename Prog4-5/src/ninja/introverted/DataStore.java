package ninja.introverted;

class DataStore {

    /* This is our Array of Linked Lists head pointer */
    /* TODO: change 'protected LLNode head;' to 'protected LLNode[] head;' */
    protected static DataStore head;
    protected static LLNode root;

    /* This is our Linked List (think of it as a node) for the ARR */
    protected static class LLNode {
        /* TODO: 'String' will get changed to 'Activities' before turning in */
        private String anActivity;
        private LLNode next;

        /* Default constructor */
        LLNode() {
            anActivity = null;
            next = null;
        }

        /* Default copy constructor */
        private LLNode(String newActivity) {
            anActivity = newActivity;
            next = null;
        }

        /* Default copy constructor w/next ptr */
        private LLNode(String newActivity, LLNode newNext) {
            anActivity = newActivity;
            next = newNext;
        }

        static LLNode newNode(String activityName) {

            LLNode temp = new LLNode();
            temp.anActivity = activityName;
            temp.next = null;
            return temp;
        }

        public static LLNode insert(LLNode root, String activityName) {

            if (root == null) {
                return newNode(activityName);
            } else
                root.next = insert(root.next, activityName);
            return root;
        }

        static void displayAll(LLNode root) {
            if (root == null)
                return;
            if (root.anActivity != null) {
                System.out.print(root.anActivity + "\n");
            }
            displayAll(root.next);
        }
    }
}
