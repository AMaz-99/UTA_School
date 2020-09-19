
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
public class LetterCount
{
  public static int countBs(String word)
  {
    int counter = 0;
    for (int i = 0; i < word.length(); i++)
    {
      if ((word.charAt(i) == 'b') || (word.charAt(i) == 'B'))
      {
        counter++;
      }
    }
    return counter;
  }

  public static void main(String[] args)
  {
    Scanner in = new Scanner(System.in);
    System.out.printf("Please enter a word: ");
    String str = in.next();

    int result = countBs(str);
    System.out.printf("%s contains letter B %d times.\n", str, result);
  }
}
