import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

/**
 * Klasa opisująca działąnie po nacisnieciu odpowiedniego klawisza
 */
	public class Klawisz implements KeyListener {
		Okno ok;
		        /**
 * Konstruktor domyslny klasy
 */
		Klawisz(Okno ok){
			this.ok=ok;
		}
		
		/** 
		 * @param e Informacja o zdazeniu
		 */
		@Override
		public void keyTyped(KeyEvent e) {
		}

		
		/** 
		 * Wykonanie interakcji z odpowiednim polem po nacisnieciu klawisza
		 * @param e Informacja o zdazeniu
		 */
		@Override
		public void keyPressed(KeyEvent e) {
			ok.ruchy++;
			if(e.getKeyChar()=='w'){
				ok.plansza[ok.x-1][ok.y].interakcja(ok, ok.x-1, ok.y);
			}
			if(e.getKeyChar()=='s'){
				ok.plansza[ok.x+1][ok.y].interakcja(ok, ok.x+1, ok.y);
			}
			if(e.getKeyChar()=='a'){
				ok.plansza[ok.x][ok.y-1].interakcja(ok, ok.x, ok.y-1);
			}
			if(e.getKeyChar()=='d'){
				ok.plansza[ok.x][ok.y+1].interakcja(ok, ok.x, ok.y+1);
			}
			ok.porusz();
			ok.wypiszp();
			ok.frame.setVisible(true);
		}

		
		/** 
		 * @param e Informacja o zdazeniu
		 */
		@Override
		public void keyReleased(KeyEvent e) {
		}
	
}