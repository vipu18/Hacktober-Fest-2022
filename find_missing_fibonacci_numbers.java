import java.util.*;
public class find_missing_fibonacci_numbers {
    public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int[] a = new int[n];
		for(int i=0;i<n;i++)
		{
		    a[i] = scan.nextInt();
		}
		Arrays.sort(a);
		if(a[0]+a[1]!=a[2] && a[1]-a[0]>a[0])
		{
		    //if(n>3 && )
		    System.out.print(a[1]-a[0]);
		    return;
		}
		
		for(int i=2;i<n;i++)
		{
		    if(a[i]!=(a[i-1]+a[i-2]))
		    {
		        System.out.print(a[i-1]+a[i-2]);
		        return;
		    }
		}
		System.out.print(a[n-1]);
	}
}
