/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.util.Scanner;

public class Spheres
{ 
  public static double userDouble(String message)
  {
    Scanner in = new Scanner(System.in);
    while (true)
    {
      System.out.printf(message);
      String s = in.next();
      double j;
      if (s.toLowerCase().equals("q"))
      {
        System.out.printf("Exiting...\n");
        System.exit(0);
      }
      try
      {
          j = Double.parseDouble(s);
      }
      catch (Exception e)
      {
         System.out.printf("%s is not a valid double.\n", s);
         continue;
      }
      if (j < 0)
      {
          System.out.printf("%f is not positive.\n", j);
          continue;
      }
      return j;
    }  
    }

    public static double sphereVolume(double radius)
    {
    // You need to complete the code for this function.
      double result = (4/3) * Math.PI * Math.pow(radius, 3);
      return result;
    }

    public static void main(String[] args)
  {
    while(true)
    {
      double r = userDouble("Please enter a radius >= 0, or q to quit: ");
      
      double volume = sphereVolume(r);
      System.out.printf("Volume = %.2f.\n\n", volume);
    }
  }
}
