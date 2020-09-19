import java.util.Scanner;

public class MonthDays
{

  
  public static int userInteger(String message)
  {
    Scanner in = new Scanner(System.in);
    int result;
    while (true)
    {
      System.out.printf(message);
      String s = in.next();
      if (s.equals("q"))
      {
        System.out.printf("Exiting...\n");
        System.exit(0);
      }
      
      try
      {
        result = Integer.parseInt(s);
      } 
      catch (Exception e)
      {
        System.out.printf("%s is not a valid number, try again.\n\n", s);
        continue;
      }
      
      if (result <= 0)
      {
        System.out.printf("%s is <= 0, try again.\n\n", s);
        continue;
      }
      return result;
    }
  }
  public static int yearDays(int year)
  {
   if (year % 100 == 0)
    {
        if (year % 400 == 0)
        {
            return 366;
        }
        else
        {
            return 365;
        }
    } 
   else
    {
        if (year % 4 == 0)
        {
            return 366;
        }
        else
        {
           return 365;
        }
    }
    
  }
 public static int monthDays(int year, int month)
 {
     if (month == 2)
     {
        if (year % 100 == 0)
            {
                if (year % 400 == 0)
                {
                        return 29;
                }
                else
                {
                         return 28;
                }
            } 
        else
        {
        if (year % 4 == 0)
            {
                return 29;
            }
        else
            {
               return 28;
            }
        } 
     }
     else if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12)) 
     {
         return 31;
     }
     else
     {
         return 30;
     }
 }
  
  public static void main(String[] args) 
  {
    Scanner in = new Scanner(System.in);
    
    while (true)
    {
      int year = userInteger("Enter a year (must be > 0): ");      
      int month = userInteger("Enter a month (must be between 1 and 12): ");
      if (month > 12)
      {
        System.out.printf("Invalid month.\n\n");
        continue;
      }

      int result = yearDays(year);
      int result2 = monthDays(year, month);

      System.out.printf("Year %d has %d days.\n", year, result);
      System.out.printf("Month %d, %d has %d days.\n\n", month, year, result2);
    }
  }
}