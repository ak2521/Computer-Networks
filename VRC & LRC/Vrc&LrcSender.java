import java.util.*;
import java.io.*;
import java.lang.*;

class Vrc&LrcSender
{
public static void main(String args[])
{
Scanner sc =new Scanner(System.in);
String in = new String();
String str="";
int i,ch,j=0;
System.out.println("Enter The Message-");
in=sc.nextLine();
String inws=in.replaceAll("\\s+","");
System.out.println("Orginal Message Before Transmission:"+inws);
System.out.println("Enter Your Choice: \n 1-Vertical Redundancy Check: \n 2-Longitudinal Redundancy Check \n");
ch=sc.nextInt();
switch(ch)
{
case 1:
	{
		int slen=inws.length();
		int n=0;
		for(i=0;i<slen;i++)
		{
			
			if(inws.charAt(i)=='1')
			{
				
				n++;
			}
		}
		System.out.println("No Of 1s:"+n);
		if(n%2==1)
		{
			str=inws+"1";
		}
		else
		{
			str=inws+"0";
		}
		System.out.println("Message With Parity Bit:"+str);
		
		try{
		File f = new File("VRC.txt");
		if (f.createNewFile()) {
        System.out.println("File created: " + f.getName());
      } else {
        System.out.println("File already exists.");
      }
    } catch (IOException e) {
      System.out.println("An error occurred.");
      e.printStackTrace();
    }        
    try {
      FileWriter myWriter = new FileWriter("VRC.txt");
      myWriter.write(str);
      myWriter.close();
      System.out.println("Successfully wrote to the file.");
    } catch (IOException e) {
      System.out.println("An error occurred.");
      e.printStackTrace();
    }
System.exit(0);
	}
case 2:
{int n=0,c1=0;
String zeros="",str1="",str2="",str3="",str4="";
int flen=inws.length();
for(i=0;i<flen;i++)
{
if(inws.charAt(i)=='1')
{
n++;
}
if(inws.charAt(i)=='0')
{
c1++;
}
}
int count=n+c1;
System.out.println("No Of Bits In The Message:"+count);
if(count<16)
{
for(i=count;i<16;i++)
{
inws=inws+'0';
}
System.out.println("16 Bit Message Created With 0's:"+inws);
}
if(count>16 && count<24)
{
for(i=count;i<24;i++)
{
inws=inws+'0';
}
System.out.println("24 Bit Message Created With 0's:"+inws);
}
if(count>24 && count<32)
{
for(i=count;i<32;i++)
{
inws=inws+'0';
}
System.out.println("32 Bit Message Created With 0's:"+inws);
}
if(count>32 && count<64)
{
for(i=count;i<64;i++)
{
inws=inws+'0';
}
System.out.println("64 Bit Message Created With 0's:"+inws);
}
flen=inws.length();
int d1,d2,d3,d4,d5,d6,d7,d8;
d1=d2=d3=d4=d5=d6=d7=d8=0;
for(i=0;i<flen;i=i+8)
{
if(inws.charAt(i)=='1')
{
d1++;
}              
}
for(i=1;i<flen;i=i+8)
{
if(inws.charAt(i)=='1')
{
d2++;
}
}
for(i=2;i<flen;i=i+8)
{
if(inws.charAt(i)=='1')
{
d3++;
}
}
for(i=3;i<flen;i=i+8)
{
if(inws.charAt(i)=='1')
{
d4++;
}
}
for(i=4;i<flen;i=i+8)
{
if(inws.charAt(i)=='1')
{
d5++;
}
}
for(i=5;i<flen;i=i+8)
{
if(inws.charAt(i)=='1')
{
d6++;
}
}
for(i=6;i<flen;i=i+8)
{
if(inws.charAt(i)=='1')
{
d7++;
}
}
for(i=7;i<flen;i=i+8)
{
if(inws.charAt(i)=='1')
{
d8++;
}
}
String a=(d1%2==1)?"1":"0";
String b=(d2%2==1)?"1":"0";
String c=(d3%2==1)?"1":"0";
String d=(d4%2==1)?"1":"0";
String e=(d5%2==1)?"1":"0";
String f=(d6%2==1)?"1":"0";
String g=(d7%2==1)?"1":"0";
String h=(d8%2==1)?"1":"0";
String redun=a+b+c+d+e+f+g+h;
System.out.println("Redundant Bit:"+redun);
inws=inws+redun;
System.out.println("Message To Be Transmitted:"+inws);
try{
                File fi = new File("VRC.txt");
                if (fi.createNewFile()) {
        System.out.println("File created: " + fi.getName());
      } else {
        System.out.println("File already exists.");
      }
    } catch (IOException e1) {
      System.out.println("An error occurred.");
      e1.printStackTrace();
    }
    try {
      FileWriter myWriter1 = new FileWriter("VRC.txt");
      myWriter1.write(inws);
      myWriter1.close();
      System.out.println("Successfully wrote to the file.");
    } catch (IOException e1) {
      System.out.println("An error occurred.");
      e1.printStackTrace();
    }
System.exit(0);
}
}
}
}
