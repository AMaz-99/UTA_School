
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
public class Middles
{
  // This function gets a double number from the user.
  // It ensures that the user enters a valid double number.  
  public static double userDouble(String message)
  {
    Scanner in = new Scanner(System.in);
    double result;
    while (true)
    {
      System.out.printf(message);
      String s = in.next();
      if (s.toLowerCase().equals("q"))
      {
        System.out.printf("Exiting...\n");
        System.exit(0);
      }
      try
      {
          result = Double.parseDouble(s);
      }
      catch (Exception e)
      {
         System.out.printf("%s is not a valid double.\n", s);
         continue;
      }
      return result;
    }
   }
    public static double pickMiddle(double first, double second, double third)
    {
        while (true)
        {
        if (((first == second) && (first == third)) || ((first == second) && (((first > third) || (first < third)))) || ((first == third) && (((first > second) || (first < second)))) || ((first > second) && (first < third)) || ((first < second) && (first > third)))  
        {
          return first;
        }
        else if (((second > first) && (second < third)) || ((third == second) && (((second > first) || (second < first)))) || ((second < first) && (second > third))|| ((first == second) && (first > third)))
        {
           return second;     
        }
        else if (((third > first) && (third < second)) || ((third < first) && (second < third)) )
        {
           return third;     
        }
        }
    }
     
  
    public static void main(String[] args)
  {
    while (true)
    {
      double first = userDouble("please enter the first number, or q to quit: ");
      double second = userDouble("please enter the second number, or q to quit: ");
      double third = userDouble("please enter the third number, or q to quit: ");
      double middle = pickMiddle(first, second, third);
      System.out.printf("the middle value is %.1f\n\n", middle);
    }
  }
}
