import java.io.*;
import java.net.*;
class FileTrans
{
    public static void uploadFile(Socket clientSocket, String filePath) throws IOException {

        InputStream inputStream = clientSocket.getInputStream();
        FileOutputStream fileOutputStream = new FileOutputStream(filePath);
        byte[] buffer = new byte[1024];
        int bytesRead;
        while ((bytesRead = inputStream.read(buffer)) != -1) {
            fileOutputStream.write(buffer, 0, bytesRead);
        }
        fileOutputStream.close();
        inputStream.close();
    }

    
    public static void downloadFile(Socket clientSocket, String filePath) throws IOException {
        OutputStream outputStream = clientSocket.getOutputStream();
        FileInputStream fileInputStream = new FileInputStream(filePath);
        byte[] buffer = new byte[1024];
        int bytesRead;
        while ((bytesRead = fileInputStream.read(buffer)) != -1) {
            outputStream.write(buffer, 0, bytesRead);
        }
        fileInputStream.close();
        outputStream.close();
    }

    public static void main(String args[])
    {
        Socket cs;
        ServerSocket ss;
        DataInputStream sin;
        DataOutputStream sout;
        DataInputStream in=new DataInputStream(System.in);
        try{
            while(true)
            {
                System.out.println("1:Send 2:Receive 3:quit");
                int ch=Integer.parseInt(in.readLine());
                if(ch==1)
                {

                    ss=new ServerSocket(5000);
                    cs=ss.accept();
                    sin=new DataInputStream(cs.getInputStream());
                    sout=new DataOutputStream(cs.getOutputStream());
                    sout.writeUTF("Connection Established");
                    System.out.println("Enter the path of file");
                    String path=in.readLine();
                    uploadFile(cs,path);
                    System.out.println("Transfer Complete");

                }
                else if(ch==2)
                {
                    System.out.println("Enter the Public Ip address of sender");
                    String ip=in.readLine();
                    cs=new Socket(ip,5000);
                    sin=new DataInputStream(cs.getInputStream());
                    System.out.println(sin.readUTF());
                    System.out.println("Enter the download path");
                    String path=in.readLine();
                    downloadFile(cs,path);
                    System.out.println("Download Complete");
                }
                else
                    System.exit(0);
            }
        }catch(Exception e)
        {
            e.printStackTrace();
        }   


    }
}