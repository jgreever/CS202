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
package program_4_5;
import java.util.Scanner;

public class Utils {

    /* Our userInput function, gets user input and returns a String */
    public Scanner userInput = new Scanner(System.in);


    /*
     * Enums: These are setup so that I can assign a quick value to
     * things like Activity Type, Garden Type, and Exercise Type.
     */

    /* Garden or Exercise Activity type */
    enum activityType {
        GARDEN, EXERCISE
    }

    /* Indoor, Outdoor, or Research for Gardening */
    enum gardenType {
        INDOOR, OUTDOOR, RESEARCH
    }

    /* Cardio, High-Intensity Interval Training, or Yoga for Exercise */
    enum exerciseType {
        CARDIO, HIIT, YOGA
    }

    /* Grab user input from user and return it as a String */
    public String getInput() {
        return userInput.nextLine();
    }


}
