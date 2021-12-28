import java.awt.*;
import java.awt.event.*;


public class Okno {

    Frame f = new Frame("okno");
    Postac pl;
    Labirnt m = new Labirnt(10);
    int[][] mapa= new int[400][400];
    {
        for(int i=0;i<mapa.length;i++){
            for (int j = 0; j < mapa.length; j++) {
                mapa[i][j]=0;
            }
        }
        for (int i = 0; i < mapa.length; i++) {
            mapa[i][0]=1;
            mapa[i][399]=1;
            mapa[0][i]=1;
            mapa[399][i]=1;
            mapa[i][1]=1;
            mapa[i][398]=1;
            mapa[1][i]=1;
            mapa[398][i]=1;
        }
    }

    Okno(){
        f.addWindowListener(new WindowAdapter(){
            public void windowClosing(WindowEvent e) {  
                f.dispose();  
            }
        });
        f.setSize(415, 438);
        MyCanvas plutno= new MyCanvas(this);
        f.add(plutno);
        f.setResizable(false);
        pl =new Postac();
        KeyListener keyList = new KeyAdapter(){
            @Override
            public void keyPressed (KeyEvent ev){
                switch (ev.getKeyChar()) {
                    case 'w':
                    if (pl.y-4>-1 && mapa[pl.x][pl.y-1]==0 && mapa[pl.x][pl.y-2]==0 && mapa[pl.x][pl.y-3]==0 && mapa[pl.x][pl.y-4]==0 &&
                        mapa[pl.x+20][pl.y-1]==0 && mapa[pl.x+20][pl.y-2]==0 && mapa[pl.x+20][pl.y-3]==0 && mapa[pl.x+20][pl.y-4]==0) {
                        pl.y=pl.y-4;
                    } 
                        break;
                        case 's':
                        if (pl.y+24<400 && mapa[pl.x][pl.y+21]==0 && mapa[pl.x][pl.y+22]==0 && mapa[pl.x][pl.y+23]==0 && mapa[pl.x][pl.y+24]==0 &&
                        mapa[pl.x+20][pl.y+21]==0 && mapa[pl.x+20][pl.y+22]==0 && mapa[pl.x+20][pl.y+23]==0 && mapa[pl.x+20][pl.y+24]==0) {
                            pl.y=pl.y+4;
                        } 
                        break;
                        case 'a':
                        if (pl.x-4>-1 && mapa[pl.x-1][pl.y]==0  && mapa[pl.x-2][pl.y]==0 && mapa[pl.x-3][pl.y]==0 && mapa[pl.x-4][pl.y]==0 && 
                        mapa[pl.x-1][pl.y+20]==0  && mapa[pl.x-2][pl.y+20]==0 && mapa[pl.x-3][pl.y+20]==0 && mapa[pl.x-4][pl.y+20]==0) {
                            pl.x=pl.x-4; 
                        }                    
                        break;
                        case 'd':
                        if (pl.x+24<400 && mapa[pl.x+21][pl.y]==0 && mapa[pl.x+22][pl.y]==0 && mapa[pl.x+23][pl.y]==0 && mapa[pl.x+24][pl.y]==0 && 
                        mapa[pl.x+21][pl.y+20]==0 && mapa[pl.x+22][pl.y+20]==0 && mapa[pl.x+23][pl.y+20]==0 && mapa[pl.x+24][pl.y+20]==0) {
                            pl.x=pl.x+4; 
                        }     
                        break;
                    default:
                        break;
                }
                plutno.repaint();
                if (pl.x<30&&pl.y<30) {
                    Dialog d = new Dialog(f , "Koniec Gry", true); 
                    Button b = new Button ("OK");  
                    d.setLayout( new FlowLayout() ); 
                    b.addActionListener ( new ActionListener()  
                    {  
                        public void actionPerformed( ActionEvent e )  
                        {  
                            d.setVisible(false);  
                            System.exit(0);
                        }  
                    });  
                    d.add( new Label ("Znalazłeś skarb i wygrałeś"));   
                    d.add(b);
                    d.setSize(200,133);    
                    d.setVisible(true);
                }
            }
        };
        plutno.addKeyListener(keyList);
        plutno.setFocusable(true);
        f.setVisible(true);
    }
}