
import java.util.Scanner;

public class LastThreeLetters
{

    public static void main(String[] args)
    {
      Scanner ronald = new Scanner(System.in); 
      System.out.printf("Pleas enter a string, at least 3 letters long: ");
      String s = ronald.next();
      int a = s.length();
      String ending = s.substring(a - 3, a);
      System.out.printf("The last three letters are %s.\n", ending);
      
              
    }
    
}
