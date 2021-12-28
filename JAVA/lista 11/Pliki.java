import java.io.File;

import javax.swing.AbstractListModel;

public class Pliki extends AbstractListModel {

    File[] tab = null;

    Pliki(){
        super();
    }
    Pliki(File f){
        super();
        tab=f.listFiles();
    }

    @Override
    public int getSize() {
        return tab==null?0:tab.length;
    }

    @Override
    public Object getElementAt(int index) {
        return tab[index];
    }

    void wypisz( File[] ft){
        tab=ft;
        fireContentsChanged(this, 0, getSize()-1);
    }
    
}
