
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
public class LetterSorting
{
  public static String sortLetters(String text)
  {
    String sorted = "";
    String converted = text.toLowerCase();
    String letters = "abcdefghijklmnopqrstuvwxyz";
    for (int j = 0; j < letters.length(); j++)
    {
        for (int i = 0; i < text.length(); i++)
        {
            char c1 = letters.charAt(j);
            char c2 = converted.charAt(i);
            if (c1 == c2)
            {
                sorted += c1;
            }
        }
    } 
    return sorted;
  }
  public static void main(String[] args) 
  {
    Scanner in = new Scanner(System.in);
    
    while (true)
    {
      System.out.printf("Enter some text, or q to quit: ");
      String text = in.nextLine();
      if (text.toLowerCase().equals("q"))
      {
        System.out.printf("Exiting...\n");
        System.exit(0);
      }
      
      String result = sortLetters(text);
      System.out.printf("Result: %s.\n\n", result);
    }
  }
}
