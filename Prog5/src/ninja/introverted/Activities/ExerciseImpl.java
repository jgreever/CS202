/*
 * Justin Greever
 * CS202 - Program 5
 * 3/17/2021
 *
 * This file is the Exercise Implementation file. It contains the derived classes:
 * Yoga, Running, Weights.
 *
 * Each class has two data members at the minimum: two String objects;
 *
 * This class "Is-A" Exercise, which "Is-A" Activity.
 *
 */
package ninja.introverted.Activities;
import ninja.introverted.Utils.UserIO;

public abstract class ExerciseImpl extends Exercise {

    public abstract void addActivity();
    public abstract void displayActivity();
    public abstract void searchActivity(String toSearch);

    public static class Yoga extends ExerciseImpl {
        String exerciseType;
        String exerciseDuration;

        public static int compareActivities(String activityOne, String activityTwo) {
            int compareThis = activityOne.compareTo(activityTwo);
            return compareThis;
        }

        @Override
        public void addActivity() {
            showExerciseType();
            this.exerciseType = UserIO.getInput();
            showExerciseDuration();
            this.exerciseDuration = UserIO.getInput();
        }
        @Override
        public void displayActivity() {
            System.out.println("Exercise Type: " + exerciseType);
            System.out.println("Exercise Duration: " + exerciseDuration);
        }
        @Override
        public void searchActivity(String toSearch) {
            if (toSearch.equals(this.exerciseType) == true) {
                System.out.println("\nMatch found");
                this.displayActivity();
            }
        }
    }

    public static class Running extends ExerciseImpl {
        String runningLength;
        String runningDuration;

        public static int compareActivities(String activityOne, String activityTwo) {
            int compareThis = activityOne.compareTo(activityTwo);
            return compareThis;
        }

        public void addActivity() {
            showRunningType();
            this.runningLength = UserIO.getInput();
            showRunningDuration();
            this.runningDuration = UserIO.getInput();
        }
        @Override
        public void displayActivity() {
            System.out.println("Running Distance: " + runningLength);
            System.out.println("Running Duration: " + runningDuration);
        }
        @Override
        public void searchActivity(String toSearch) {
        }
    }

    public static class Weights extends ExerciseImpl {
        String weightActivity;
        String weightAmount;

        public static int compareActivities(String activityOne, String activityTwo) {
            int compareThis = activityOne.compareTo(activityTwo);
            return compareThis;
        }

        @Override
        public void addActivity() {
            showWeightType();
            this.weightActivity = UserIO.getInput();
            showWeightDuration();
            this.weightAmount = UserIO.getInput();
        }
        @Override
        public void displayActivity() {
            System.out.println("Weightlifting Activity: " + weightActivity);
            System.out.println("Weightlifting Amount: " + weightAmount);
        }
        @Override
        public void searchActivity(String toSearch) {
        }
    }
}
