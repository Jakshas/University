enum Pierwiastki{
    H(1,1,"Wodór"),
    He(2,2,"Hel"),
    Li(3,7,"Lit"),
    Be(4,9,"Beryl"),
    B(5,11,"Bor"),
    C(6,12,"Węgiel"),
    N(7,14,"Azot"),
    O(8,16,"Tlen"),
    F(9,19,"Fluor"),
    Ne(10,20,"Neon"),
    Na(11,23,"Sód"),
    Mg(12,24,"Magnez"),
    Al(13,27,"Glin"),
    Si(14,28,"Krzem"),
    P(15,31,"Fosfor"),
    S(16,32,"Siarka"),
    Cl(17,37,"Chlor"),
    Ar(18,1,"Argon"),;

    int licz_a; 
    int licz_m; 
    String nazwa;

    Pierwiastki(int licz_a, int licz_m, String nazwa){
        this.licz_a=licz_a;
        this.licz_m=licz_m;
        this.nazwa=nazwa;
    }
    @Override
    public String toString() {
        return this.licz_a + " " + this.licz_m + " " +this.nazwa;
    }

public static void main(String[] args) {
    System.out.println(Pierwiastki.H);
    }
}
