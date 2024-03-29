import java.awt.*;
import java.awt.event.*;

public class AWT_Example{
    public static void  main(String args[]){
        Frame frame=new Frame("Demo");
        Label label=new Label("Hello");
    
        label.setAlignment(Label.CENTER);

        frame.add(label);
        frame.setSize(300,300);

        frame.setVisible(true);

        frame.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
    }
}