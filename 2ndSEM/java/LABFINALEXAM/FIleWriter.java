import java.io.*;
public class FIleWriter {
    public static void main(String[] args) {
		try {
		File fe= new File("a.txt");
		FileWriter fw=new FileWriter(fe);
	    fw.write("Helllo");
	    System.out.println("Sucsessfully created and file written");
	    fw.close();
	}
	catch(Exception e) {System.out.println(e);}
    }
}
