package ninja.introverted;

public class Main extends DataStore {
    public static void main(String[] args) {

        LLNode newNode = new LLNode();
        LLNode.insert(newNode, "A String to insert");
        LLNode.insert(newNode, "Another string to add to the list");
        LLNode.insert(newNode, "This is the last string to add to this list tonight");
        LLNode.displayAll(newNode);
    }
}
