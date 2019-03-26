import java.util.Random;

public class º∆À„¶–
{
    public static double getApproximation(int n)
    {
        Random rnd = new Random();
        int k = 0;
        double x, y;
        for(int i = 1; i <= n; i++)
        {
            x = rnd.nextDouble();
            y = rnd.nextDouble();
            if((x * x + y * y) <= 1)
                k++;
        }

        return (((double) 4 * k) / n);
    }

    public static void main(String[] args)
    {
        System.out.println(getApproximation(5000000000000000000000000));
    }
}