import java.awt.*;
import java.awt.event.*;

public class AWTControlsExample extends Frame {
    public AWTControlsExample() {
        // Set the layout manager
        setLayout(new FlowLayout());

        // Create and add AWT controls
        Canvas canvas = new Canvas();
        Label label = new Label("Label:");
        Button button = new Button("Button");
        TextField textField = new TextField("TextField", 20);
        TextArea textArea = new TextArea("TextArea", 5, 20);
        Choice choice = new Choice();
        Checkbox checkbox1 = new Checkbox("Checkbox 1");
        Checkbox checkbox2 = new Checkbox("Checkbox 2");
        CheckboxGroup checkboxGroup = new CheckboxGroup();
        Checkbox checkbox3 = new Checkbox("Checkbox 3", checkboxGroup, false);
        List list = new List(3, true);

        choice.add("Option 1");
        choice.add("Option 2");
        choice.add("Option 3");

        list.add("Item 1");
        list.add("Item 2");
        list.add("Item 3");
        list.add("Item 4");

        add(canvas);
        add(label);
        add(button);
        add(textField);
        add(textArea);
        add(choice);
        add(checkbox1);
        add(checkbox2);
        add(checkbox3);
        add(list);

        // Set frame properties
        setTitle("AWT Controls Example");
        setSize(300, 400);
        setVisible(true);

        // Add window listener to handle window close event
        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                dispose(); // Close the frame
            }
        });
    }
    
    public static void main(String[] args) {
        new AWTControlsExample(); // Create an instance of the AWTControlsExample class
    }
}
