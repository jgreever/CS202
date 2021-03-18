package ninja.introverted.Activities;

import ninja.introverted.Utils.UserIO;

public abstract class RelaxImpl extends Relax {

    public abstract void addActivity();
    public abstract void displayActivity();
    public abstract void searchActivity(String toSearch);

    public static class Reading extends RelaxImpl {
        String readWhat;
        String readNext;

        public static int compareActivities(String activityOne, String activityTwo) {
            int compareThis = activityOne.compareTo(activityTwo);
            return compareThis;
        }

        @Override
        public void addActivity() {
            showReadWhat();
            this.readWhat = UserIO.getInput();
            showReadNext();
            this.readNext = UserIO.getInput();
        }
        @Override
        public void displayActivity() {
            System.out.println("Currently Reading: " + readWhat);
            System.out.println("Reading Next: " + readNext);
        }
        @Override
        public void searchActivity(String toSearch) {
        }
    }

    public static class Writing extends RelaxImpl {
        String typeOfWriting;
        String pagesOfWriting;

        @Override
        public void addActivity() {
        }
        @Override
        public void displayActivity() {
        }
        @Override
        public void searchActivity(String toSearch) {
        }
    }

    public static class Napping extends RelaxImpl {
        String napTime;
        String howLong;

        @Override
        public void addActivity() {
        }
        @Override
        public void displayActivity() {
        }
        @Override
        public void searchActivity(String toSearch) {
        }
    }
}
