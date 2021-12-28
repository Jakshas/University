public class zad1 {
    public static void main(String[] args) {
        int n=Integer.parseInt(args[0]),wysokosc,szerokosc;
        if(n<2||n>200){
            throw new IllegalArgumentException("parametr spoza zakresu 2...200");
        }
        int[][] tab=new int[n][n];
        if(n%2==0){
            wysokosc=n/2;
            szerokosc=n/2-1;
        }else{
            wysokosc=n/2;
            szerokosc=n/2;
        }
        tab[wysokosc][szerokosc]=1;
        int kierunek=0,kroki=1,pozostale=kroki;
        for(int i=2;i<=n*n;i++){
            if(pozostale==0){
                kierunek++;
                if(kierunek%2==0){
                    kroki++;
                }
                pozostale=kroki;
            }
            switch (kierunek%4) {
                case 0:
                    szerokosc++;
                    tab[wysokosc][szerokosc]=i;
                    break;
                case 1:
                    wysokosc--;
                    tab[wysokosc][szerokosc]=i;
                    break;
                case 2:
                    szerokosc--;
                    tab[wysokosc][szerokosc]=i;
                    break;
                case 3:
                    wysokosc++;
                    tab[wysokosc][szerokosc]=i;
                    break;
                default:
                    break;
            }
            pozostale--;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!pierwsze(tab[i][j])){
                    tab[i][j]=0;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(tab[i][j]>0){
                    System.out.print("*");
                }else{
                    System.out.print(" ");
                }
            }
            System.out.println();
        }
    }
    public static boolean pierwsze(int l) {
        if(l==1){
            return false;
        }
        for(int i=2;i<=Math.sqrt(l);i++){
            if(l%i==0){
                return false;
            }
        }
        return true;
    }
}
