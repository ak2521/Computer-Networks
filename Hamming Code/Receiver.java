import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class Receiver{

    public static void main(String args[]){
        try {
            String value ="";
            int redudent=4;
            int oddcount=0;
            int evencount=0;
            Scanner sc = new Scanner(new File("file.txt"));
            String transmitted = sc.next();
            ArrayList<Integer> al = new ArrayList<>();
            String[] array = transmitted.split("");
            int[] arr = new int[array.length];
            for (int i = 0; i < array.length; i++) {
                arr[i] = Integer.valueOf(array[i]);
            }
            for(int i:arr){
                al.add(i);
            }
            for (int i = 0; i < redudent; i++) {
                int x = (int)Math.pow(2, i);
                for (int k = 1; k < arr.length; k++) {
                    if (((k >> i) & 1) == 1) {
                            if(arr[k]==1){
                                oddcount++;
                            }else{
                                evencount++;
                            }
                    }
                }if(oddcount%2==0 && evencount%2==0){
                    System.out.println("r" + x + " = " +"0");
                    value+="0";
                }else{
                    System.out.println("r" + x + " = " +"1");
                    value+="1";


                }
            }
            int xr = Integer.parseInt(value,2);
            if(al.get(xr)==1){
                al.set(xr,0);
            }else{
                al.set(xr,1);
            }
            System.out.println("hence the receided bits are:");
            al.remove(0);
            for(int i=0;i<al.size();i++){
                System.out.print(al.get(i));
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}
