import java.io.*;
import java.util.*;
import  java.lang.*;
import java.io.*;
class CharstuffSender
{    
    public static void main(String args[])
    {
        Scanner k =new Scanner (System.in);
        System.out.println("enter the string\t");
        String s=k.nextLine();
         String str1;
         String str2="";
        int i,m,j;
        m=s.length();   
        System.out.println("original data     "+s);
       str1="stx";
       for(i=0;i<=m-1;i++)
       {
         if(((s.charAt(i)=='d')&&(s.charAt(i+1)=='l')&&(s.charAt(i+2)=='e'))||((s.charAt(i)=='e')&&(s.charAt(i+1)=='t')&&(s.charAt(i+2)=='x')))
        {
        str1=str1+"dle";
        }
        str1=str1+s.substring(i,i+1);
    }

    str1=str1+"etx";
    System.out.println("transmitted data      "+str1);
    try {
      File myObj = new File("CharStuffing.txt");
      if (myObj.createNewFile()) {
        System.out.println("File created: " + myObj.getName());
      } else {
        System.out.println("File already exists.");
      }
    } catch (IOException e) {
      System.out.println("An error occurred.");
      e.printStackTrace();
    }        
    try {
      FileWriter myWriter = new FileWriter("CharStuffing.txt");
      myWriter.write(str1);
      myWriter.close();
      System.out.println("Successfully wrote to the file.");
    } catch (IOException e) {
      System.out.println("An error occurred.");
      e.printStackTrace();
    }
}
}
