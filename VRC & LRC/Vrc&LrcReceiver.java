import java.util.*;
import java.io.*;
import java.lang.*;

class ed2
{
public static void main(String args[]) throws Exception
{
Scanner sc=new Scanner(System.in);
int ch,i;
String str1="";
String re = new String();
String out = new String();
 File file = new File("VRC.txt");
        BufferedReader br= new BufferedReader(new FileReader(file));
        StringBuilder sb = new StringBuilder();
        String st=br.readLine();
        while(st!=null)
        {
            sb.append(st);
            st=br.readLine();
        }
        String str = sb.toString();
	String inws=str;
        System.out.println(" Data In The File:"+str);
	System.out.println("Enter Your Choice: \n 1-Vertical Redundancy Check: \n 2-Longitudinal Redundancy Check: \n");
ch=sc.nextInt();
switch(ch)
{
case 1:
{
int slen=str.length();
		int c=0;
		for(i=0;i<slen;i++)
		{
			
			if(str.charAt(i)=='1')
			{
				
				c++;
			}
		}
		System.out.println("No Of 1s:"+c);
		if(c%2==0)
		{
		System.out.println("The Recieved Message Is Correct");
		for(i=0;i<slen-1;i++)
		{
		re=re+str.substring(i,i+1);
		
		}
		  System.out.println("Original Message:"+re);	
		}
		else
		{
		System.out.println("The Recieved Message Contains Error");
}
		System.exit(0);
		
}
case 2:
{
int flen=str.length();
int d1,d2,d3,d4,d5,d6,d7,d8,n,c1;
d1=d2=d3=d4=d5=d6=d7=d8=n=c1=0;
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
System.out.println("Resultant Parity Bits:"+redun);
int fcount=0;
for(i=0;i<redun.length();i++)
{
if(redun.charAt(i)=='0')
{
fcount++;
}
}
System.out.println("No Of Zeros In Resulting Even Parity:"+fcount);


if(fcount==8)
{
System.out.println("The Received Is Correct");
System.out.println("Original Message:"+inws.substring(0,inws.length()-8));
}

if(fcount!=8)
{
System.out.println("Error Attered");
System.exit(0);
}
}
}
}
}

