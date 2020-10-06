//Dishi Jain github: @dishijn2
//Java program to find the minimum edit distance between two given strings
//to find minimum number operations to convert string1 to string2 
public class Mineditdistance {
    public int mineditdistance(String s1, String s2) {
        int len1 = s1.length();
        int len2 = s2.length();
		// Create a table to store results of subproblems
        int a[][] = new int[len1+1][len2+1];
		
		// If second string is empty, only option is to 
        // remove all characters of second string
        for (int i = 0; i <=len1; i++) {
            a[i][0] = i;
        }
		// If first string is empty, only option is to 
        // insert all characters of second string 
        for(int j=0;j<=len2;j++){
            a[0][j]=j;        
        }
		
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
				// If last characters are same, ignore last char 
				// and recur for remaining string 
                if(s1.charAt(i-1) == s2.charAt(j-1)){
                    a[i][j] = a[i-1][j-1];
                }
				// If the last character is different, consider all 
                // possibilities and find the minimum
                else {
                    int q = Math.min(a[i-1][j],a[i][j-1]);
					a[i][j] = 1+Math.min(q,a[i-1][j-1]);
                }
            }
        }
    return a[len1][len2];
    }
    public static void main(String[] args) {
        Mineditdistance m = new Mineditdistance();
        String s1 = "acef";
        String s2 = "azcef";
        System.out.println(m.mineditdistance(s1,s2));
    }
}