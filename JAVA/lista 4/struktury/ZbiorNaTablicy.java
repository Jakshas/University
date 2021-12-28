package struktury;

public class ZbiorNaTablicy extends Zbior{
    Para tab[];
    ZbiorNaTablicy(int i){
        tab= new Para[i];
    }
    @Override
    public Para szukaj(String k) throws Exception {
        for (Para para : tab) {
            if(para.klucz==k){
                return para;
            }
        }
        throw new Exception("nie znaleziono pary");
    }

    @Override
    public void wstaw(Para p) throws Exception {
        int i=0;
        while (tab[i]!=null && i<tab.length && !tab[i].equals(p)) {
            i++;
        }
        if (tab[i]!=null && tab[i].equals(p)) {
            throw new Exception("element o kluczu juz istanieje");
        }
        if(i>=tab.length){    
            throw new Exception("tablica pełna");
        }
        tab[i]=p;
    }

    @Override
    public void usuń(String k) {
        int i=0;
        while (i<tab.length && tab[i]!=null && tab[i].klucz!=k) {
            i++;
        }
        if(i>=tab.length){

        }else{
            while (i<tab.length-1 && tab[i+1]!=null) {
                tab[i]=tab[i+1];
                i++;
            }
            tab[i]=null;
        }
    }

    @Override
    public double czytaj(String k) throws Exception {
        int i = 0;
        while (tab[i].klucz != k && i < tab.length) {
            i++;
        }
        if(i>=tab.length){
            throw new Exception("nie znaleziono elementu");
        }
        return tab[i].getWartość();
    }

    @Override
    public void ustaw(Para p) throws Exception {
        int i = 0;
        while (tab[i]!=null && tab[i].klucz != p.klucz && i < tab.length) {
            i++;
        }
        if(i>=tab.length){
            throw new Exception("nie znaleziono elementu i tablica jest pełna");
        }
        tab[i]=p;
    }

    @Override
    public void czysc() {
        int i=0;
        while (i < tab.length && tab[i] != null) {
            tab[i]=null;
            i++;
        }
    }

    @Override
    public int ile() {
        int ile=0,i=0;
        while (i < tab.length && tab[i] != null){
            i++;
            ile++;
        }
        return ile;
    }

    @Override
    public boolean szukajtf(String k) throws Exception {
        for (Para para : tab) {
            if(para.klucz==k){
                return true;
            }
        }
        return false;
    }
    
}
