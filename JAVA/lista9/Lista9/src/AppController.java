import java.math.BigInteger;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.CheckBox;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;

public class AppController {

    BigInteger poprzednia = new BigInteger("0");
    BigInteger zmienna = new BigInteger("0");
    BigInteger systemliczb = new BigInteger("10");
    @FXML
    private Button i4;

    @FXML
    private Button i7;

    @FXML
    private Button i8;

    @FXML
    private Button i9;

    @FXML
    private Button i5;

    @FXML
    private Button i6;

    @FXML
    private Button i1;

    @FXML
    private Button i2;

    @FXML
    private Button i3;

    @FXML
    private Button i0;

    @FXML
    private Button zmiensnak;

    @FXML
    private Button modulo;

    @FXML
    private Button A;

    @FXML
    private Button C;

    @FXML
    private Button D;

    @FXML
    private Button B;

    @FXML
    private Button E;

    @FXML
    private Button F;

    @FXML
    private Button rownasie;

    @FXML
    private Button dziel;

    @FXML
    private Button mnoz;

    @FXML
    private Button odejmij;

    @FXML
    private Button dodaj;

    @FXML
    private CheckBox s2;

    @FXML
    private CheckBox s10;

    @FXML
    private CheckBox s16;

    @FXML
    private Button cofnij;

    @FXML
    private Button usun;

    @FXML
    private Button pow;

    @FXML
    private Button silnia;

    @FXML
    private Button newton;
    @FXML
    private Label label;

    @FXML
    private TextField textfield;

    @FXML
    void click0(ActionEvent event) {
        zmienna = (zmienna.multiply(systemliczb));
        textfield.setText(textfield.getText() + 0);
    }

    @FXML
    void click1(ActionEvent event) {
        zmienna = (zmienna.multiply(systemliczb)).add(new BigInteger("1"));
        textfield.setText(textfield.getText() + 1);
    }

    @FXML
    void click2(ActionEvent event) {
        zmienna = (zmienna.multiply(systemliczb)).add(new BigInteger("2"));
        textfield.setText(textfield.getText() + 2);
    }

    @FXML
    void click3(ActionEvent event) {
        zmienna = (zmienna.multiply(systemliczb)).add(new BigInteger("3"));
        textfield.setText(textfield.getText() + 3);
    }

    @FXML
    void click4(ActionEvent event) {
        zmienna = (zmienna.multiply(systemliczb)).add(new BigInteger("4"));
        textfield.setText(textfield.getText() + 4);
    }

    @FXML
    void click5(ActionEvent event) {
        zmienna = (zmienna.multiply(systemliczb)).add(new BigInteger("5"));
        textfield.setText(textfield.getText() + 5);
    }

    @FXML
    void click6(ActionEvent event) {
        zmienna = (zmienna.multiply(systemliczb)).add(new BigInteger("6"));
        textfield.setText(textfield.getText() + 6);
    }

    @FXML
    void click7(ActionEvent event) {
        zmienna = (zmienna.multiply(systemliczb)).add(new BigInteger("7"));
        textfield.setText(textfield.getText() + 7);
    }

    @FXML
    void click8(ActionEvent event) {
        zmienna = (zmienna.multiply(systemliczb)).add(new BigInteger("8"));
        textfield.setText(textfield.getText() + 8);
    }

    @FXML
    void click9(ActionEvent event) {
        zmienna = (zmienna.multiply(systemliczb)).add(new BigInteger("9"));
        textfield.setText(textfield.getText() + 9);
    }

    @FXML
    void clickA(ActionEvent event) {
        zmienna = (zmienna.multiply(systemliczb)).add(new BigInteger("10"));
        textfield.setText(textfield.getText() + "A");
    }

    @FXML
    void clickB(ActionEvent event) {
        zmienna = (zmienna.multiply(systemliczb)).add(new BigInteger("11"));
        textfield.setText(textfield.getText() + "B");
    }

    @FXML
    void clickC(ActionEvent event) {
        zmienna = (zmienna.multiply(systemliczb)).add(new BigInteger("12"));
        textfield.setText(textfield.getText() + "C");
    }

    @FXML
    void clickD(ActionEvent event) {
        zmienna = (zmienna.multiply(systemliczb)).add(new BigInteger("13"));
        textfield.setText(textfield.getText() + "D");
    }

    @FXML
    void clickE(ActionEvent event) {
        zmienna = (zmienna.multiply(systemliczb)).add(new BigInteger("14"));
        textfield.setText(textfield.getText() + "E");
    }

    @FXML
    void clickF(ActionEvent event) {
        zmienna = (zmienna.multiply(systemliczb)).add(new BigInteger("15"));
        textfield.setText(textfield.getText() + "F");
    }

    @FXML
    void clickcofnij(ActionEvent event) {
        int ln = textfield.getLength();
        if (zmienna.toString(10) != "0") {
            zmienna = zmienna.divide(systemliczb);
            textfield.setText(textfield.getText().substring(0, ln - 1));
        }
    }

    @FXML
    void clickdodaj(ActionEvent event) {
        BigInteger val = poprzednia.add(zmienna);
        if (s2.isSelected()) {
            label.setText(val.toString(2));
        }
        if (s16.isSelected()) {
            label.setText(val.toString(16));
        }
        if (s10.isSelected()) {
            label.setText(val.toString(10));
        }
        zmienna = new BigInteger("0");
        poprzednia = val;
        textfield.setText("");
    }

    @FXML
    void clickdziel(ActionEvent event) {
        BigInteger val = poprzednia.divide(zmienna);
        if (s2.isSelected()) {
            label.setText(val.toString(2));
        }
        if (s16.isSelected()) {
            label.setText(val.toString(16));
        }
        if (s10.isSelected()) {
            label.setText(val.toString(10));
        }
        zmienna = new BigInteger("0");
        poprzednia = val;
        textfield.setText("");
    }

    @FXML
    void clickmnoz(ActionEvent event) {
        BigInteger val = poprzednia.multiply(zmienna);
        if (s2.isSelected()) {
            label.setText(val.toString(2));
        }
        if (s16.isSelected()) {
            label.setText(val.toString(16));
        }
        if (s10.isSelected()) {
            label.setText(val.toString(10));
        }
        zmienna = new BigInteger("0");
        poprzednia = val;
        textfield.setText("");
    }

    @FXML
    void clickodejmij(ActionEvent event) {
        BigInteger val = poprzednia.subtract(zmienna);
        if (s2.isSelected()) {
            label.setText(val.toString(2));
        }
        if (s16.isSelected()) {
            label.setText(val.toString(16));
        }
        if (s10.isSelected()) {
            label.setText(val.toString(10));
        }
        zmienna = new BigInteger("0");
        poprzednia = val;
        textfield.setText("");
    }

    @FXML
    void clickmodulo(ActionEvent event) {
        BigInteger val = poprzednia.mod(zmienna);
        if (s2.isSelected()) {
            label.setText(val.toString(2));
        }
        if (s16.isSelected()) {
            label.setText(val.toString(16));
        }
        if (s10.isSelected()) {
            label.setText(val.toString(10));
        }
        zmienna = new BigInteger("0");
        poprzednia = val;
        textfield.setText("");
    }

    @FXML
    void clickrownasie(ActionEvent event) {
        BigInteger val = zmienna;
        if (s2.isSelected()) {
            label.setText(val.toString(2));
        }
        if (s16.isSelected()) {
            label.setText(val.toString(16));
        }
        if (s10.isSelected()) {
            label.setText(val.toString(10));
        }
        zmienna = new BigInteger("0");
        poprzednia = val;
        textfield.setText("");
    }

    @FXML
    void clickpow(ActionEvent event) {
        BigInteger val = poprzednia.pow(zmienna.intValue());
        if (s2.isSelected()) {
            textfield.setText(val.toString(2));
        }
        if (s16.isSelected()) {
            textfield.setText(val.toString(16));
        }
        if (s10.isSelected()) {
            textfield.setText(val.toString(10));
        }
        zmienna = val;
    }

    @FXML
    void clicknewton(ActionEvent event) {
        BigInteger val = silnia(poprzednia).divide(silnia(zmienna).multiply(silnia(poprzednia.subtract(zmienna))));
        if (s2.isSelected()) {
            label.setText(val.toString(2));
        }
        if (s16.isSelected()) {
            label.setText(val.toString(16));
        }
        if (s10.isSelected()) {
            label.setText(val.toString(10));
        }
        zmienna = new BigInteger("0");
        poprzednia = val;
        textfield.setText("");
    }

    BigInteger silnia(BigInteger zm) {
        BigInteger val = new BigInteger("1");
        for (BigInteger i = new BigInteger("2"); i.compareTo(zm) <= 0; i = i.add(new BigInteger("1"))) {
            val = val.multiply(i);
        }
        return val;
    }

    @FXML
    void clicksilnia(ActionEvent event) {
        if (zmienna.compareTo(new BigInteger("0")) < 0) {

        } else {
            BigInteger val = new BigInteger("1");
            for (BigInteger i = new BigInteger("2"); i.compareTo(zmienna) <= 0; i = i.add(new BigInteger("1"))) {
                val = val.multiply(i);
            }
            zmienna = val;
            if (s2.isSelected()) {
                textfield.setText(val.toString(2));
            }
            if (s16.isSelected()) {
                textfield.setText(val.toString(16));
            }
            if (s10.isSelected()) {
                textfield.setText(val.toString(10));
            }
        }
    }

    @FXML
    void clicks16(ActionEvent event) {
        A.setDisable(false);
        B.setDisable(false);
        C.setDisable(false);
        D.setDisable(false);
        E.setDisable(false);
        F.setDisable(false);
        i1.setDisable(false);
        i2.setDisable(false);
        i3.setDisable(false);
        i4.setDisable(false);
        i5.setDisable(false);
        i6.setDisable(false);
        i7.setDisable(false);
        i8.setDisable(false);
        i9.setDisable(false);
        i0.setDisable(false);
        systemliczb = new BigInteger("16");
        zmienna = new BigInteger("0");
        poprzednia = new BigInteger("0");
        textfield.setText("");
        label.setText("0");
        s2.setSelected(false);
        s10.setSelected(false);
    }

    @FXML
    void clicks2(ActionEvent event) {
        A.setDisable(true);
        B.setDisable(true);
        C.setDisable(true);
        D.setDisable(true);
        E.setDisable(true);
        F.setDisable(true);
        i1.setDisable(false);
        i2.setDisable(true);
        i3.setDisable(true);
        i4.setDisable(true);
        i5.setDisable(true);
        i6.setDisable(true);
        i7.setDisable(true);
        i8.setDisable(true);
        i9.setDisable(true);
        i0.setDisable(false);
        systemliczb = new BigInteger("2");
        zmienna = new BigInteger("0");
        poprzednia = new BigInteger("0");
        textfield.setText("");
        label.setText("0");
        s16.setSelected(false);
        s10.setSelected(false);
    }

    @FXML
    void clicks10(ActionEvent event) {
        A.setDisable(true);
        B.setDisable(true);
        C.setDisable(true);
        D.setDisable(true);
        E.setDisable(true);
        F.setDisable(true);
        i1.setDisable(false);
        i2.setDisable(false);
        i3.setDisable(false);
        i4.setDisable(false);
        i5.setDisable(false);
        i6.setDisable(false);
        i7.setDisable(false);
        i8.setDisable(false);
        i9.setDisable(false);
        i0.setDisable(false);
        systemliczb = new BigInteger("10");
        zmienna = new BigInteger("0");
        poprzednia = new BigInteger("0");
        textfield.setText("");
        label.setText("0");
        s16.setSelected(false);
        s2.setSelected(false);
    }

    @FXML
    void clickusun(ActionEvent event) {
        label.setText("0");
        zmienna = new BigInteger("0");
        poprzednia = new BigInteger("0");
        textfield.setText("");
    }

    @FXML
    void clickzmiensnak(ActionEvent event) {
        BigInteger val = zmienna.multiply(new BigInteger("-1"));
        zmienna = val;
        textfield.setText(String.valueOf(val));
    }
}
