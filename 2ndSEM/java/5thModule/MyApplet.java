import java.applet.*;
import java.awt.*;
import java.awt.event.*;
import java.net.URL;

public class MyApplet extends Applet implements ActionListener {
    private Image image;
    private AudioClip sound;

    public void init() {
        // Load image
        image = getImage(getDocumentBase(), "image.jpg");

        // Load sound
        sound = getAudioClip(getDocumentBase(), "sound.wav");

        // Add button
        Button playButton = new Button("Play Sound");
        playButton.addActionListener(this);
        add(playButton);
    }

    public void start() {
        // Applet starting
        System.out.println("Applet started");
    }

    public void stop() {
        // Applet stopping
        System.out.println("Applet stopped");
    }
    

    public void paint(Graphics g) {
        // Draw image
        if (image != null) {
            g.drawImage(image, 0, 0, getWidth(), getHeight(), this);
        }
    }

    public void actionPerformed(ActionEvent e) {
        // Play sound when button is clicked
        if (e.getActionCommand().equals("Play Sound")) {
            if (sound != null) {
                sound.play();
            }
        }
    }
}
