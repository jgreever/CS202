/*
 * Justin Greever
 * CS202 - Program 4
 * 3/5/2021
 *
 * This is the Utility class for Program 4. It will help us get
 * things like user input, displaying messages, possible "operator"
 *
 * overloading (function overloading more like it), and possibly
 * some test functions to ensure the program does what it should.
 *
 */
package ninja.introverted.Utils;

import java.util.Scanner;

public class UserIO {
    /* Our userInput function, gets user input and returns a String */
    public static final Scanner userInput = new Scanner(System.in);

    /* Grab user input and return it as a String */
    public static String getInput() {
        return userInput.nextLine();
    }

    /* Grab user input and return it as an Int */
    public static int getChoice() {
        return userInput.nextInt();
    }

    /* Display output to the user for various input functions */
    public static void showExerciseType() {
        System.out.println("\nPlease enter the Yoga activity to do: ");
    }

    public static void showRunningType() {
        System.out.println("\nPlease enter the distance to run: ");
    }

    public static void showRunningDuration() {
        System.out.println("\nPlease enter the time to run for: ");
    }

    public static void showExerciseDuration() {
        System.out.println("\nPlease enter the duration of time for the activity: ");
    }

    public static void showWeightType() {
        System.out.println("\nPlease enter the time to run for: ");
    }

    public static void showWeightDuration() {
        System.out.println("\nPlease enter the duration of time for the activity: ");
    }

    public static void showReadWhat() {
        System.out.println("\nWhat are you currently reading: ");
    }

    public static void showReadNext() {
        System.out.println("\nWhat will you read next: ");
    }

    public static int whatTypeOfActivity() {
        System.out.println("\nWhat type of Activity would you like to enter?");
        System.out.println("(1) Exercise, (2) Running, (3) Weights, (4) Napping, (5) Reading, (6) Writing: ");
        int retInt = userInput.nextInt();
        userInput.nextLine();
        return retInt;
    }
}