import java.util.*;
import java.io.*;
public class BitStuffingSender
      {
      public static void main(String[] args)
        {
              Scanner sc=new Scanner(System.in);
              System.out.print("Enter the message:-");
              String d = sc.nextLine();
	      String d1=d.replaceAll("\\s+","");
              String remaining = new String();
              String output=new String();
              int counter = 0;
              for(int i=0;i<d1.length();i++)
                {
                   if (d1.charAt(i)!='1' && d1.charAt(i)!='0')
                        {
                            System.out.println("Enter valid Binary values");
                            return;
                        }
                   if(d1.charAt(i) == '1')
                        {
                            counter++;
                            remaining = remaining + d1.charAt(i);
                        }
                   else
                        {
                            remaining = remaining + d1.charAt(i);
                            counter = 0;
                        }
                   if(counter == 5)
                        {
                            remaining = remaining + '0';
                            counter = 0;
                        }
                }
            String new1="01111110"+remaining+"01111110";
            System.out.println("Stuffed Data:");
	    System.out.println(new1);
             try {
      File myObj = new File("BitStuffing.txt");
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
      FileWriter myWriter = new FileWriter("BitStuffing.txt");
      myWriter.write(new1);
      myWriter.close();
      System.out.println("Successfully wrote to the file.");
    } catch (IOException e) {
      System.out.println("An error occurred.");
      e.printStackTrace();
    }
}
}
