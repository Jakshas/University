package struktury;

public class ZbiorNaTablicyDynamicznej extends ZbiorNaTablicy {

    public ZbiorNaTablicyDynamicznej() {
        super(2);
    }
    @Override
    public void wstaw(Para p) throws Exception {
        int i=0;
        while (i<tab.length && tab[i]!=null && !tab[i].equals(p)) {
            i++;
        }
        if (i<tab.length && tab[i]!=null && tab[i].equals(p)) {
            throw new Exception("element o kluczu juz istanieje");
        }
        if(i>=tab.length){
            Para[] pom = new Para[tab.length*2];
            for (int j = 0; j < tab.length; j++) {
                pom[j]=tab[j];
            }
            tab=pom;
        }
        tab[i]=p;
    }

    @Override
    public void usuń(String k) {
        int i=0;
        while (tab[i].klucz!=k && tab[i]!=null && i<tab.length) {
            i++;
        }
        if(i>=tab.length){

        }else{
            while (i<tab.length-1 && tab[i+1]!=null) {
                tab[i]=tab[i+1];
                i++;
            }
            tab[i]=null;
            if (i<tab.length/4) {
                Para[] pom = new Para[tab.length/2];
                for (int j = 0; j < tab.length/2; j++) {
                    pom[j]=tab[j];
                }
                tab=pom;
            }
        }
    }

    @Override
    public void ustaw(Para p) throws Exception {
        int i = 0;
        while (tab[i]!=null && tab[i].klucz != p.klucz && i < tab.length) {
            i++;
        }
        if(i>=tab.length){
            Para[] pom = new Para[tab.length*2];
            for (int j = 0; j < tab.length*2; j++) {
                pom[j]=tab[j];
            }
            tab=pom;
        }
        tab[i]=p;
    }
    public void czysc() {
        tab=new Para[2];
    }
    @Override
    public boolean szukajtf(String k) throws Exception {
        for (Para para : tab) {
            if(para!=null&&para.klucz==k){
                return true;
            }
        }
        return false;
    }
}
