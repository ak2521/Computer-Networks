import java.io.*;  
import java.net.*;
import java.util.Scanner;  
public class JC {  
public static void main(String[] args) throws Exception {
    int port=0;
    Scanner sx=new Scanner(System.in);
    System.out.println("Enter Message");
    String input=sx.nextLine();
    System.out.println("Enter port No:");
    port=sx.nextInt();
    System.out.println("[+] Connecting to port->"+port);
System.out.println("");
System.out.println("<- Connection Established ->");
Socket s=new Socket("localhost",port);  
DataOutputStream dout=new DataOutputStream(s.getOutputStream());  
dout.writeUTF(input);
DataInputStream din=new DataInputStream(s.getInputStream());
String str=din.readUTF();
System.out.println("");
System.out.println("Message From Server:"+str);    
dout.close();
s.close();
System.out.println("");
System.out.println("[+] Connection Closed");
System.out.println("");
}
}  
