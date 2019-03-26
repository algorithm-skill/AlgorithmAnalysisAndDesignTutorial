import java.util.*;
public class 数组主元素
{

    public static Map<Integer, Integer> map = new HashMap<Integer, Integer>();
    public static void getMainElement(int[] arr)
    {
        Random rnd = new Random();
        int x = rnd.nextInt(arr.length);
        int k = 0;
        for(int i = 0; i < arr.length; i++)             //这里要注意不要越界    
            if(arr[x] == arr[i])
                k++;
        if(k >= (arr.length / 2))
            map.put(arr[k], k);
    }

    public static void main(String[] args)
    {
        int[] arr = { 5, 8, 9, 5, 5, 5 };
        for(int i = 1; i <= 100000; i++)
            getMainElement(arr);
        Iterator iter = map.entrySet().iterator();              //这里要注意iterator()是一个方法
        while(iter.hasNext())
        {
            Map.Entry entry = (Map.Entry) iter.next();
            System.out.println(entry.getKey());
        }
    }
}