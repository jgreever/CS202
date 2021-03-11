package program_4_5.utils;

import program_4_5.activity.Activity;

public class Menu {
    /*
     * This is where we will perform our tests to ensure that all
     * functions work and all ADTs perform as they should.
     */
    public static void MainMenu() {
        Activity newActivity = new Activity();
        int menuChoice;

        while (true) {
            System.out.println("\n******************************");
            System.out.println("\tProgram 4 Test Menu\t");
            System.out.println("1. Enter an Activity");
            System.out.println("2. Display all Activities");
            System.out.println("3. Search for an Activity");
            System.out.println("4. Exit the program");
            System.out.println("******************************\n\n");
            System.out.println("Enter your choice please: ");
            menuChoice = Utils.getChoice();

            /*
             * This is our switch construct for performing operations that
             * are in the menu as well as allowing the user to exit the
             * program safely.
             */
            switch (menuChoice) {

                /* Adds a new activity to the list */
                case 1 -> newActivity.addActivity();

                /* Displays the activities on the list */
                case 2 -> newActivity.displayActivity();

                /* Search for an activity in the list */
                case 3 -> newActivity.searchActivity();

                /*
                 * The exit menu below is just for playing around with. I used it to
                 * tinker with a few ideas for preventing accidental exiting of the
                 * program and what not, hence why the code currently is always true
                 * when you choose case 4, so that I could change variables at a later
                 * time if needed.
                 */
                case 4 -> {
                    int doQuit;
                    System.out.println("\nPress (1) to exit, (0) to stay in the program");
                    doQuit = Utils.getChoice();
                    if (doQuit == 1) {
                        System.out.println("\nThank you for using Program 4.\nHave a wonderful day!\n");
                        System.out.println("\nMade with\n");
                        System.out.println("""
                                                                                  \s
                                         ,---._                                   \s
                                       .-- -.' \\                                  \s
                                       |    |   :                                 \s
                                       :    ;   |                                 \s
                                       :        |               .---.             \s
                                       |    :   :  ,--.--.    /.  ./|   ,--.--.   \s
                                       :          /       \\ .-' . ' |  /       \\  \s
                                       |    ;   |.--.  .-. /___/ \\: | .--.  .-. | \s
                                   ___ l          \\__\\/: . .   \\  ' .  \\__\\/: . . \s
                                 /    /\\    J   : ," .--.; |\\   \\   '  ," .--.; | \s
                                /  ../  `..-    ,/  /  ,.  | \\   \\    /  /  ,.  | \s
                                \\    \\         ;;  :   .'   \\ \\   \\ |;  :   .'   \\\s
                                 \\    \\      ,' |  ,     .-./  '---" |  ,     .-./\s
                                  "---....--'    `--`---'             `--`---'    \s""");
                        System.exit(0);
                    }
                }

                /* The default option if a user presses the wrong key */
                default -> System.out.println("\nInvalid choice, please try again.");
            }
        }
    }
}
