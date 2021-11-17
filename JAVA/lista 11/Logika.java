import java.io.File;
import java.io.FileFilter;

public class Logika {
    
    Okno o;
    File f;
    File[] ft;
    Pliki p;
    File selected;

    void przypiszpliki(File ff){

        if (ff.isDirectory()) {
            f=ff;
            if (f.getParentFile()==null) {
                ft = new File[f.listFiles().length];
                File[] fss2 = f.listFiles(new FileFilter(){
                    @Override
                    public boolean accept(File file) {
                        return !file.isDirectory();
                }
                });
                File[] fss1 = f.listFiles(new FileFilter(){
                    @Override
                    public boolean accept(File file) {
                        return file.isDirectory();
                }
                });
                int i = 0;
                for (File file : fss1) {
                    ft[i] = file;
                    i++;
                }               
                for (File file : fss2) {
                    ft[i] = file;
                    i++;
                }
            }else{
                ft = new File[f.listFiles().length+1];
                ft[0]=f.getParentFile();
                File[] fss2 = f.listFiles(new FileFilter(){
                    @Override
                    public boolean accept(File file) {
                        return !file.isDirectory();
                }
                });
                File[] fss1 = f.listFiles(new FileFilter(){
                    @Override
                    public boolean accept(File file) {
                        return file.isDirectory();
                }
                });
                int i = 1;
                for (File file : fss1) {
                    ft[i] = file;
                    i++;
                }               
                for (File file : fss2) {
                    ft[i] = file;
                    i++;
                }
            }
            p.wypisz(ft);
            o.file.setText(ff.getName());
        }

    }

    Logika(Okno ok){
        o=ok;
        p=new Pliki();
    }
}
