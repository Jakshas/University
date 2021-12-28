import java.awt.Component;

import javax.swing.BorderFactory;
import javax.swing.DefaultListCellRenderer;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.ListCellRenderer;
import java.awt.*;

public class Kreslarz implements ListCellRenderer {
    
    protected DefaultListCellRenderer defaultRenderer = new DefaultListCellRenderer();

<<<<<<< HEAD
    
=======
>>>>>>> 17217ae776ba9628dbc9594a72934a138d91aa54
    @Override
    public Component getListCellRendererComponent(JList list, Object value, int index, boolean isSelected,
            boolean cellHasFocus) {
                JLabel renderer = (JLabel) defaultRenderer.getListCellRendererComponent(list, value, index,
                isSelected, cellHasFocus);
            renderer.setBorder(BorderFactory.createLineBorder(Color.black));
            if (renderer.getText().charAt(0)=='N') {
                renderer.setForeground(Color.red);
            }
        return renderer;
    }
    
}
