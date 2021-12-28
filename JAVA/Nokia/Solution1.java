import java.util.*;

class Solution1 {
    static public int solution(String S) {
        char st[] = S.toCharArray();
        ArrayList<Character> al = new ArrayList<Character>();
        for(char c : st){
            al.add(c);
        }
        if(checkstring(al))
            return -1;
        int wynik = 0;
        for(int i = 0;i<=S.length() + wynik;i++){
            int j = 0;
            while(!checkstringinplace(al,i)){
                al.add(i,'a');
                j++;
            }
            al.remove(i);
            j--;
            wynik += j;
        }

        return wynik;
    }

    static boolean checkstring(ArrayList<Character> al){
        int aa = 0;
        for(int i = 0; i < al.size();i++){
            if(al.get(i)=='a'){
                aa++;
                if(aa == 3){
                    return true;
                }
            }else{
                aa = 0;
            }
        }
        return false;
    }
    static boolean checkstringinplace(ArrayList<Character> al, int idx){
        if(idx >= al.size()){
            return false;
        }
        if(al.size()- idx > 2 && al.get(idx) == 'a' && al.get(idx + 1) == 'a' && al.get(idx + 2) == 'a'){
            return true;
        }
        if(al.size() - idx > 1 && idx > 0 && al.get(idx-1) == 'a' && al.get(idx) == 'a' && al.get(idx + 1) == 'a'){
            return true;
        }
        if(idx >= 2 && al.get(idx) == 'a' && al.get(idx-1) == 'a' && al.get(idx-2) == 'a'){
            return true;
        }
        return false;
    }
    public static void main(String[] args) {
        String s = "aabab";
        solution(s);
    }
}