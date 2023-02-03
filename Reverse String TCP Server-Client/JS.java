import java.io.*;  
import java.net.*;
import java.util.Scanner;  
public class JS {  
public static void main(String[] args) throws Exception {
    int port;
    Scanner sx=new Scanner(System.in);
    System.out.println("Enter port No:");
    port=sx.nextInt();
    System.out.println("[+] Listening to port->"+port);
while(true)
{
try{
ServerSocket ss=new ServerSocket(port);  
Socket s=ss.accept();//establishes connection
DataInputStream dis=new DataInputStream(s.getInputStream());
DataOutputStream dout =new DataOutputStream(s.getOutputStream());  
String  str=(String)dis.readUTF();
System.out.println("");
System.out.println("<- Accepted Client->");
System.out.println("");
System.out.println("message From Client: "+str);
System.out.println("");
int MessLen =str.length();
char ch;
String Reverse="";
for(int i=0;i<MessLen ;i++)
{
ch=str.charAt(i);
Reverse=ch+Reverse;
}
System.out.println("Reversed Message= "+Reverse);
dout.writeUTF(Reverse);  
ss.close();
System.out.println("");
System.out.println("Connecttion Closed....");
System.out.println("");
System.out.println("");
}catch(Exception e){System.out.println(e);}  
}  
}
}  
