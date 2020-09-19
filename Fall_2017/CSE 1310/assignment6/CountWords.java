
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Brocard
 */
public class CountWords
{
 public static int countWords(String text)
 {
     int counter = 0;
     int length = text.length();
     String letters = "qwertyuiopasdfghjklzxcvbnm";
     for (int i = 0; i < length; i++)
     {
         if (i == 0)
         {
             if (letters.indexOf(text.charAt(i)) != -1)
                 counter++;
         }
        if (text.charAt(i)==' ')
        {
            if (letters.indexOf(text.charAt(i+1)) != -1)
                counter++;
        }
     }
     return counter;
 }
  
  public static void main(String[] args) 
  {
    Scanner in = new Scanner(System.in);
    
    while (true)
    {
      System.out.printf("Enter some text, or q to quit: ");
      String text = in.nextLine();
      if (text.equals("q"))
      {
        System.out.printf("Exiting...\n");
        break;
      }
      int result = countWords(text);
      System.out.printf("Counted %d words.\n\n", result);
    }
  }
}

