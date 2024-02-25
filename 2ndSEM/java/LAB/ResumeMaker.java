import java.io.IOException;
import java.util.Scanner;
import org.apache.pdfbox.pdmodel.*;
import org.apache.pdfbox.pdmodel.font.*;
import org.apache.pdfbox.pdmodel.common.*;
import org.apache.pdfbox.pdmodel.edit.*;

public class ResumeMaker {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Gather personal information
        System.out.println("Enter your name:");
        String name = scanner.nextLine();
        System.out.println("Enter your email:");
        String email = scanner.nextLine();
        System.out.println("Enter your phone number:");
        String phoneNumber = scanner.nextLine();

        // Gather education details
        System.out.println("\nEnter your education details:");
        System.out.println("Enter your degree:");
        String degree = scanner.nextLine();
        System.out.println("Enter your major:");
        String major = scanner.nextLine();
        System.out.println("Enter your university:");
        String university = scanner.nextLine();
        System.out.println("Enter your graduation year:");
        int graduationYear = scanner.nextInt();

        // Gather work experience
        scanner.nextLine(); // consume newline
        System.out.println("\nEnter your work experience:");
        System.out.println("Enter your job title:");
        String jobTitle = scanner.nextLine();
        System.out.println("Enter your company:");
        String company = scanner.nextLine();
        System.out.println("Enter your start year:");
        int startYear = scanner.nextInt();
        System.out.println("Enter your end year (or 0 if still working there):");
        int endYear = scanner.nextInt();
        scanner.nextLine(); // consume newline
        System.out.println("Enter your job description:");
        String jobDescription = scanner.nextLine();

        // Gather skills
        System.out.println("\nEnter your skills (comma-separated list):");
        String skills = scanner.nextLine();

        // Generate PDF resume
        try {
            PDDocument document = new PDDocument();
            PDPage page = new PDPage();
            document.addPage(page);
            PDPageContentStream contentStream = new PDPageContentStream(document, page);

            contentStream.setFont(PDType1Font.HELVETICA_BOLD, 16);
            contentStream.beginText();
            contentStream.newLineAtOffset(100, 700);
            contentStream.showText("RESUME");
            contentStream.endText();

            contentStream.setFont(PDType1Font.HELVETICA, 12);
            contentStream.beginText();
            contentStream.newLineAtOffset(100, 680);
            contentStream.showText("Name: " + name);
            contentStream.newLine();
            contentStream.showText("Email: " + email);
            contentStream.newLine();
            contentStream.showText("Phone: " + phoneNumber);
            contentStream.newLine();
            contentStream.showText("Education:");
            contentStream.newLine();
            contentStream.showText("- Degree: " + degree);
            contentStream.newLine();
            contentStream.showText("- Major: " + major);
            contentStream.newLine();
            contentStream.showText("- University: " + university);
            contentStream.newLine();
            contentStream.showText("- Graduation Year: " + graduationYear);
            contentStream.newLine();
            contentStream.showText("Work Experience:");
            contentStream.newLine();
            contentStream.showText("- Job Title: " + jobTitle);
            contentStream.newLine();
            contentStream.showText("- Company: " + company);
            contentStream.newLine();
            contentStream.showText("- Start Year: " + startYear);
            contentStream.newLine();
            contentStream.showText("- End Year: " + (endYear == 0 ? "Present" : endYear));
            contentStream.newLine();
            contentStream.showText("- Job Description: " + jobDescription);
            contentStream.newLine();
            contentStream.showText("Skills: " + skills);
            contentStream.endText();

            contentStream.close();
            document.save("resume.pdf");
            document.close();

            System.out.println("Resume generated successfully. Please check the resume.pdf file.");
        } catch (IOException e) {
            System.err.println("Error occurred while generating the resume: " + e.getMessage());
        }

        scanner.close();
    }
}
