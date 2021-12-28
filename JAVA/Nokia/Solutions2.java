public class Solutions2 {
    public static void main(String[] args) {
        String s1 = "15:15:00";
        String s2 = "15:15:12";
        System.out.println(solution(s1,s2));
    }

    public static int solution(String S, String T) {
        String arrS[] = S.split(":");
        String arrT[] = T.split(":");
        int iS[] = {Integer.valueOf(arrS[0]),Integer.valueOf(arrS[1]),Integer.valueOf(arrS[2])};
        int iT[] = {Integer.valueOf(arrT[0]),Integer.valueOf(arrT[1]),Integer.valueOf(arrT[2])};
        int wynik = 0;
        checkIfIntresting(arrT[0]+arrT[1]+arrT[2]);
        while(!checkTabs(iS,iT)){
            if(iS[0]<10){
                arrS[0] = "0" + iS[0]; 
            }else{
                arrS[0] = "" + iS[0];
            }
            while(!checkTabs(iS,iT) && iS[1]<60){
                if(iS[1]<10){
                    arrS[1] = "0" + iS[1]; 
                }else{
                    arrS[1] = "" + iS[1];
                }
                while(!checkTabs(iS,iT) && iS[2]<60){
                        if(iS[2]<10){
                            arrS[2] = "0" + iS[2]; 
                        }else{
                            arrS[2] = "" + iS[2];
                        }
                        if(checkIfIntresting(arrS[0]+arrS[1]+arrS[2])){
                            wynik++;
                        }
                        iS[2]++;
                }
                if (checkTabs(iS,iT))
                    break;
                iS[2]=0;
                iS[1]++;
            }
            if (checkTabs(iS,iT))
            break;
            iS[1]=0;
            iS[0]++;
            if(iS[0]==24){
                iS[0] = 0;
            }
        }
        return wynik;
    }
    public static boolean checkTabs(int iS[],int iT[]){
        return iS[0]==iT[0] && iS[1]==iT[1] && iS[2]==iT[2];
    }

    public static boolean checkIfIntresting(String S){
        int[] arr = new int[10];
        int count = 0;
        for(int i = 0; i<S.length();i++){
            if (S.charAt(i) == ':') {
                continue;
            }
            int digit = S.charAt(i) - 48;
            if (arr[digit] == 0){
                arr[digit] = 1;
                count++;
                if(count > 2){
                    return false;
                }
            }
        }
        return true;
    }
}
