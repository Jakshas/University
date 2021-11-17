import java.awt.Component;
import java.io.File;
import java.util.Date;
import java.awt.Color;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.imageio.ImageIO;
import javax.swing.BorderFactory;
import javax.swing.DefaultListCellRenderer;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.ListCellRenderer;

public class Kreslarz implements ListCellRenderer {

    Logika l;

    Kreslarz(Logika logika) {
        l = logika;
    }

    protected DefaultListCellRenderer defaultRenderer = new DefaultListCellRenderer();

    @Override
    public Component getListCellRendererComponent(JList list, Object value, int index, boolean isSelected,
            boolean cellHasFocus) {
            String s;
            if (l.f.getParentFile() != null && ((File) value).getPath().equals(l.f.getParentFile().getPath())) {
               s = "..";
            } else {
                s = ((File) value).getName() + "  " + new Date(((File) value).lastModified()).toString();
            }

            JLabel renderer = (JLabel) defaultRenderer.getListCellRendererComponent(list, s, index, isSelected, cellHasFocus);
            renderer.setBorder(BorderFactory.createLineBorder(Color.black));
            renderer.setToolTipText(((File) value).length() / (1024 * 1024) + " mb");
            renderer.setSize(300, 20);

            if (((File)value).isDirectory()) {
                renderer.setForeground(Color.blue);
            }

            if (isImage((File)value)) {
                renderer.setForeground(Color.red);
            }


        return renderer ;
    }

    public static boolean isImage(File file)
    {
        try {
            return ImageIO.read(file) != null;
        } catch (Exception e) {
            return false;
        }
    }
    
}
