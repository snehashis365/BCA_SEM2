import java.util.*;
class test
{
	public static void main(String []args)throws InterruptedException
	{
		int x=10;
		int y=++x + ++x + ++x + ++x;
		/*System.out.print("Please Wait...");
		String arr[]=new String[3];
		arr[0]="/";
		arr[1]="|";
		arr[2]="\\\";
		while(i<10)
		{
			System.out.print(arr[j]);
			j++;
			Thread.sleep(300);
			System.out.print("\b");
			Thread.sleep(300);
			i++;
			if(j==2)
				j=0;
		}
		*/
		System.out.println(y);
	}
}

