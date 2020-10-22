import java.util.Scanner;
class stringordering
{
    public static void main(String[] args)
    {
        //String name[]={"madras","bombay","calc"};
        String name[]=new String[100];
        Scanner sc=new Scanner(System.in);
        for(int i=0;i<3;i++)
        name[i]=sc.nextLine();
        int size= name.length;
        String temp=null;
        for(int i=0;i<size;i++)
        {
            for(int j=i+1;j<size;j++)
            {
                if(name[j].compareTo(name[i])<0)
                {
                    temp=name[i];
                    name[i]=name[j];
                    name[j]=temp;
                }
            }
        }
        for(int i=0;i<size;i++)
        {
            System.out.println(name[i]);
        }
    }
}