import java.util.*;

public class Solution3 {
    public static void main(String[] args) {
        String s1 = "admin  -wx 29 Sep 1983        833 source.h\nadmin  r-x 23 Jun 2003     854016 blockbuster.mpeg\nadmin  --x 02 Jul 1997        821 delete-this.py\nadmin  -w- 15 Feb 1971      23552 library.dll\nadmin  --x 15 May 1979  645922816 logs.zip\njane   --x 04 Dec 2010      93184 old-photos.rar\njane   -w- 08 Feb 1982  681574400 important.java\nadmin  rwx 26 Dec 1952   14680064 to-do-list.txt";
        solution(s1);
    }
    public static String solution(String S) {
        Scanner s = new Scanner(S);
        String pom="";
        ArrayList<String[]> datelist = new ArrayList<String[]>();
        while(s.hasNextLine()){
            pom = s.nextLine();
            Scanner s2 = new Scanner(pom);
            String spom1 = s2.next();
            if (spom1.equals("admin")) {
                String spom2 = s2.next();
                if (spom2.charAt(2)=='x') {
                    String[] pomtab = new String[3];
                    for (int i = 0; i < pomtab.length; i++) {
                        pomtab[i] = s2.next();
                    }
                    int size = Integer.valueOf(s2.next());
                    if (size<14680064) {
                        datelist.add(pomtab);
                    }
                }
            }
        }
        ArrayList<Date> conlint = new ArrayList<Date>();
        for (String[] date : datelist) {
            conlint.add(new Date(date[0]+"-"+date[1]+"-"+date[2]));
        }
        Collections.sort(conlint);
        String odp = conlint.get(0).toString();
        Scanner s3 = new Scanner(odp);
        s3.next();
        String odp2 = s3.next();
        String odp1 = s3.next();
        s3.next();
        s3.next();
        String odp3 = s3.next();
        return odp1+" "+odp2+" "+odp3;
    }
}
