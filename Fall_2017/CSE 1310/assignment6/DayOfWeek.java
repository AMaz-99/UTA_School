import java.util.Scanner;

public class DayOfWeek
{
    public static boolean yearDays(int year)
  {
   if (year % 100 == 0)
    {
        if (year % 400 == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    } 
   else
    {
        if (year % 4 == 0)
        {
            return true;
        }
        else
        {
           return false;
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
 public static int daysPassed(int year, int month, int day)
 {
     int days_passed = 0;
     for (int i = 1000; i <year; i++)
     {
        if (yearDays(i) == true)
        {
            days_passed += 366;
        }
        else 
        {
            days_passed += 365;
        }
                 
     }
     for (int j = 1; j < month; j++)
     {
        days_passed += monthDays(year, j);
     }
     days_passed = days_passed + day;
     return days_passed;
 }
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
 public static String dayOfWeek(int year, int month, int day)
 {
     String[] days = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
     int d = daysPassed(year, month, day);
     if (d % 7 == 0)
     {
         return days[1];
     }
     else if (d % 7 == 1)
     {
         return days[2];
     }
     else if (d % 7 == 2)
     {
         return days[3];
     }
     else if (d % 7 == 3)
     {
         return days[4];
     }
     else if (d % 7 == 4)
     {
         return days[5];
     }
     else if (d % 7 == 5)
     {
         return days[6];
     }
     else
     {
         return days[0];
     }
 }
  
  public static void main(String[] args) 
  {
    Scanner in = new Scanner(System.in);
    
    while (true)
    {
      int year = userInteger("Enter a year (must be >= 1000): ");      
      if (year < 1000)
      {
        System.out.printf("Invalid year.\n\n");
        continue;
      }

      int month = userInteger("Enter a month(must be between 1 and 12): ");
      if (month > 12)
      {
        System.out.printf("Invalid month.\n\n");
        continue;
      }
      
      int day = userInteger("Enter a day: ");
      
      int result = daysPassed(year, month, day);
      System.out.printf("%d days have passed from 12/31/999 to %d/%d/%d.\n", 
                        result, month, day, year);
      
      String day_name = dayOfWeek(year, month, day);
      System.out.printf("%d/%d/%d is a %s.\n\n", month, day, year, day_name);
    }
  }
}