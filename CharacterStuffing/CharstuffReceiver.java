import java.io.*;
import java.util.*;
import  java.lang.*;
import java.io.*;
class CharstuffReceiver
{    
    public static void main(String args[]) throws Exception
    {
        String str2="";
        int i;
	    File file = new File("CharStuffing.txt");
        BufferedReader br= new BufferedReader(new FileReader(file));
        StringBuilder sb = new StringBuilder();
        String st=br.readLine();
        while(st!=null)
        {
            sb.append(st);
            st=br.readLine();
        }
        String str1 = sb.toString();
        System.out.println("Stuffed Data:"+str1);
        int p=str1.length();
	String xz="",xc="";
xz=str1.substring(0,3);
if(!xz.equals("stx"))
{
System.out.println("Starting Frame Error");
System.exit(0);
}
xz=str1.substring(p-3,p);
if(!xz.equals("etx"))
{
System.out.println("Ending Frame Error");
System.exit(0);
}
boolean isFound=false,isFound1=false;
for(i=3;i<p-3;i++)
{
isFound=str1.contains("dleetx");
isFound1=str1.contains("dledle");
}
if(isFound!=true)
{
System.out.println("Message Error");
System.exit(0);
}
if(isFound1!=true)
{
System.out.println("Message Error");
System.exit(0);
}
        for(i=0;i<p;i++)
    {
        if(((str1.charAt(i)=='d')&&(str1.charAt(i+1)=='l')&&(str1.charAt(i+2)=='e')&&(str1.charAt(i+3)=='d')&&(str1.charAt(i+4)=='l')&&(str1.charAt(i+5)=='e'))||((str1.charAt(i)=='d')&&(str1.charAt(i+1)=='l')&&(str1.charAt(i+2)=='e')&&(str1.charAt(i+3)=='e')&&(str1.charAt(i+4)=='t')&&(str1.charAt(i+5)=='x')))
        {
            i=i+3;
        }
	
        str2=str2+str1.substring(i,i+1);
    }
int plen=str2.length();
  	   System.out.println("received data is:"+str2.substring(3,plen-3));
    }
}
