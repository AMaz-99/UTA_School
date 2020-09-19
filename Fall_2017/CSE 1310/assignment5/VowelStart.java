
import java.util.Scanner;

public class VowelStart
{
    public static boolean startsWithVowel(String word)
    {
      while (true)
      {
       char c = word.charAt(0);
       if ("aeiouAEIOU".indexOf(c)!= -1)
        {
        return true;
        } 
       return false;
      }
    }
    public static void main(String[] args)
    {
     Scanner in = new Scanner(System.in);
    
     while (true)
     {
      System.out.printf("Enter some word, or q to quit: ");
      String word = in.next();
      if (word.toLowerCase().equals("q"))
      {
        System.out.printf("Exiting...\n");
        System.exit(0);
      }
      boolean result = startsWithVowel(word);
      if (result == true)
      {
        System.out.printf("Yes, %s starts with a vowel.\n\n", word);
      } 
      else
      {
        System.out.printf("No, %s does not start with a vowel.\n\n", word);
      }
     }
  }
    
}
