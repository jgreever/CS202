/*
 * Justin Greever
 * CS202 - Program 4
 * 3/5/2021
 *
 * This is the Utility class for Program 4. It will help us get
 * things like user input, displaying messages, possible "operator"
 * overloading (function overloading more like it), and possibly
 * some test functions to ensure the program does what it should.
 *
 */
package program_4_5.utils;
import java.util.Scanner;

public class Utils {

    /* Our userInput function, gets user input and returns a String */
    public static final Scanner userInput = new Scanner(System.in);

    /*
     * Enums: These are setup so that I can assign a quick value to
     * things like Activity Type, Garden Type, and Exercise Type.
     */

    /* Garden or Exercise Activity type */
    public enum activityType {
        GARDEN, EXERCISE
    }

    /* Indoor, Outdoor, or Research for Gardening */
    public enum gardenType {
        INDOOR, OUTDOOR, RESEARCH
    }

    /* Cardio, High-Intensity Interval Training, or Yoga for Exercise */
    public enum exerciseType {
        CARDIO, HIIT, YOGA
    }

    /* Grab user input and return it as a String */
    public static String getInput() {
        return userInput.nextLine();
    }

    /* Grab user input and return it as an Int */
    public static int getChoice() {
        return userInput.nextInt();
    }


}
