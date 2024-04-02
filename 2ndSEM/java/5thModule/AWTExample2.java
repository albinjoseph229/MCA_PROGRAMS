import java.awt.*;
import java.awt.event.*;

public class AWTExample2 extends Frame {
    public AWTExample2() {
        // Set the layout manager
        setLayout(new BorderLayout());

        // Create components
        Button button = new Button("Click Me");
        Checkbox checkbox = new Checkbox("Check Me");
        Label label = new Label("Enter Text:");
        TextField textField = new TextField();
        TextArea textArea = new TextArea();
        
        // Add components to the frame
        add(button, BorderLayout.NORTH);
        add(checkbox, BorderLayout.WEST);
        add(label, BorderLayout.CENTER);
        add(textField, BorderLayout.EAST);
        add(textArea, BorderLayout.SOUTH);

        // Create a menu bar
        MenuBar menuBar = new MenuBar();
        
        // Create menus
        Menu fileMenu = new Menu("File");
        Menu editMenu = new Menu("Edit");

        // Create menu items
        MenuItem newItem = new MenuItem("New");
        MenuItem openItem = new MenuItem("Open");
        MenuItem saveItem = new MenuItem("Save");
        MenuItem exitItem = new MenuItem("Exit");

        MenuItem cutItem = new MenuItem("Cut");
        MenuItem copyItem = new MenuItem("Copy");
        MenuItem pasteItem = new MenuItem("Paste");

        // Add menu items to menus
        fileMenu.add(newItem);
        fileMenu.add(openItem);
        fileMenu.add(saveItem);
        fileMenu.addSeparator();
        fileMenu.add(exitItem);

        editMenu.add(cutItem);
        editMenu.add(copyItem);
        editMenu.add(pasteItem);

        // Add menus to menu bar
        menuBar.add(fileMenu);
        menuBar.add(editMenu);

        // Set the menu bar to the frame
        setMenuBar(menuBar);

        // Set frame properties
        setTitle("AWT Example");
        setSize(400, 300);
        setVisible(true);

        // Add window listener to handle window close event
        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                dispose(); // Close the frame
            }
        });
    }

    public static void main(String[] args) {
        new AWTExample2(); // Create an instance of the AWTExample class
    }
}
