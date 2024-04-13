import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.event.*;

public class SwingBasicsExample extends JFrame implements ActionListener {
    private JButton button;
    private JRadioButton radioButton1, radioButton2;
    private JTextArea textArea;
    private JComboBox<String> comboBox;
    private JTable table;
    private JColorChooser colorChooser;
    private JProgressBar progressBar;
    private JSlider slider;

    public SwingBasicsExample() {
        setTitle("Swing Basics Example");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new FlowLayout());

        // JButton
        button = new JButton("Click Me");
        button.addActionListener(this);
        add(button);

        // JRadioButtons
        radioButton1 = new JRadioButton("Option 1");
        radioButton2 = new JRadioButton("Option 2");
        ButtonGroup radioButtonGroup = new ButtonGroup();
        radioButtonGroup.add(radioButton1);
        radioButtonGroup.add(radioButton2);
        add(radioButton1);
        add(radioButton2);

        // JTextArea
        textArea = new JTextArea(5, 20);
        add(new JScrollPane(textArea));
        // JComboBox
        comboBox = new JComboBox<>(new String[]{"Item 1", "Item 2", "Item 3"});
        add(comboBox);

        // JTable
        String[][] data = {{"1", "Name 1"}, {"2", "Name 2"}, {"3", "Name 3"}};
        String[] columns = {"ID", "Name"};
        table = new JTable(data, columns);
        add(new JScrollPane(table));

        // JColorChooser
        colorChooser = new JColorChooser();
        add(colorChooser);

        // JProgressBar
        progressBar = new JProgressBar(0, 100);
        progressBar.setValue(50);
        progressBar.setStringPainted(true);
        add(progressBar);

        // JSlider
        slider = new JSlider(JSlider.HORIZONTAL, 0, 100, 50);
        slider.setMinorTickSpacing(10);
        slider.setMajorTickSpacing(20);
        slider.setPaintTicks(true);
        slider.setPaintLabels(true);
        add(slider);

        setSize(400, 400);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == button) {
            JOptionPane.showMessageDialog(this, "Button clicked!");
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new SwingBasicsExample());
    }
}
