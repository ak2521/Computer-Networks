import java.util.*;
import  java.lang.*;
import java.io.*;
class BitStuffingReceiver
{    
    public static void main(String args[]) throws Exception
    {   String remaining="";
        int counter=0;
        String output = new String();
     int i;
        File file = new File("Bitstuffing.txt");
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
String xz="";
xz=str1.substring(0,8);
if(!xz.equals("0111110"))
{
System.out.println("Starting Frame Error");
System.exit(0);
}
xz=str1.substring(p-8,p);
if(!xz.equals("01111110"))
{
System.out.println("Ending Frame Error");
System.exit(0);
}
   
        for(i=9;i<p-9;i++)
        {
            remaining=remaining+str1.substring(i,i+1);
        }
     System.out.println("Extracted Data:"+remaining);
      for( i=0;i<remaining.length();i++)
                {
                    if(remaining.charAt(i) == '1')
                        {
                            counter++;
                            output = output + remaining.charAt(i);
                        }
                    else
                        {
                             output = output +remaining.charAt(i);
                             counter = 0;
                        }
                   if(counter == 5)
                        {
                              if((i+2)!=remaining.length())
                              {
				if(remaining.charAt(i+1).equals(0))
				{
                            output=output+remaining.charAt(i+2);
                              }
				else
				{
					System.out.println("Message Error Occured");
					System.exit(0);
					}
				}
                              else
                              {
                                output=output + '1';
                              }
                              i=i+2;
                              counter = 1;
                        }
               }
             System.out.println("Destuffed Data is: "+output);
       }
}
       

