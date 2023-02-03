import java.io.*;
import java.util.Arrays;
import java.util.Scanner;
import java.lang.*;

public class Sender {
    static  int[] getRedudent(int[] arr , int redudent){
        for (int i = 0; i < redudent; i++) {
            int x = (int)Math.pow(2, i);
            for (int k = 1; k < arr.length; k++) {
                if (((k >> i) & 1) == 1) {
                    if (x != k)
                        arr[x] = arr[x]^arr[k];
                }
            }
            System.out.println("r" + x + " = " + arr[x]);

        }return arr;
    }
    public static  void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the bits:");
        String message = sc.next();
        int redudent =0;
        int len = message.length();
        for(int i=0;i<32;i++){
            if(Math.pow(2,i)>= len + i +1){
                redudent=i;
                break;
            }
        }
        int length = len +redudent;
        System.out.println(length);
        int[] arr = new int[len+redudent+1];
        System.out.println(arr.length);
        int j=0;
        for(int i=1;i<arr.length;i++) {
            if ((Math.ceil(Math.log(i) / Math.log(2)) - Math.floor(Math.log(i) / Math.log(2))) == 0){
                arr[i]= 0;//place zero in power of 2th places
            }else{
                arr[i]=(int)(message.charAt(j)-'0');//convert it into actual intger value
                j++;
            }
        }

        arr =getRedudent(arr,redudent);
        System.out.println("the hamming code value is :");
        for (int i = 1; i < arr.length; i++) {
            System.out.print(arr[i]);
        }
        System.out.println();
        String answer = Arrays.toString(arr).replaceAll("\\[|\\]|,|\\s", "");
        String received = answer.substring(1,answer.length());
        String receivedmessage = "0"+received;

        byte[] bytes = receivedmessage.getBytes();
        File f = new File("file.txt");
        try {
            FileOutputStream fo = new FileOutputStream(f);
            fo.write(bytes);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }


    }
}
