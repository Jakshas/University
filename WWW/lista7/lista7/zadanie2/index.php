<!DOCTYPE html>
<html>
    <head>
    <style>
    .valid{
        color: green;
    }
    .invaild{
        color: red;
    }
    </style>
    </head>
    <body>

    <form action="index.php" method="post">
        Nr. karty
        <input class="<?php if (isset($_POST["nr"]) && preg_match('/^[0-9]{4}-[0-9]{4}-[0-9]{4}-[0-9]{4}$/', $_POST['nr'])){ echo 'valid';}else {echo 'invaild';}?>" type="text" name="nr" value="<?php if(isset($_POST["nr"])){echo $_POST['nr'];} ?>"><br>
        Data ważności
        <input class="<?php if (isset($_POST["data"]) && preg_match('/^[0-1][0-9]\/[0-2][0-9][0-9][0-9]$/', $_POST['data'])){ echo 'valid';}else {echo 'invaild';}?>" type="text" name='data' value="<?php if(isset($_POST["data"])){echo $_POST['data'];} ?>"><br>
        CVC
        <input class="<?php if (isset($_POST["cvc"]) && preg_match('/^\d\d\d$/', $_POST['cvc'])){ echo 'valid';}else {echo 'invaild';}?>" type="text" name='cvc' value="<?php if(isset($_POST["cvc"])){echo $_POST['cvc'];} ?>"><br>
        Imie
        <input class="<?php if (isset($_POST["imie"]) && preg_match('/^[A-Z][a-z]+$/', $_POST['imie'])){ echo 'valid';}else {echo 'invaild';}?>" type="text" name='imie' value="<?php if(isset($_POST["imie"])){echo $_POST['imie'];} ?>"><br>
        Nazwisko
        <input class="<?php if (isset($_POST["nazwisko"]) && preg_match('/^[A-Z][a-z]+$/', $_POST['nazwisko'])){ echo 'valid';}else {echo 'invaild';} ?>" type="text" name='nazwisko' value="<?php if(isset($_POST["nazwisko"])){echo $_POST['nazwisko'];} ?>"><br>
        Adres
        <input class="<?php if (isset($_POST["adres"]) && preg_match('/^[A-Z][a-z]+ [0-9]+ [A-Z][a-z]+$/', $_POST['adres'])){ echo 'valid';}else {echo 'invaild';}?>" type="text" name="adres" value="<?php if(isset($_POST["adres"])){echo $_POST['adres'];} ?>"><br>
        Nr. telefonu
        <input class="<?php if (isset($_POST["tel"]) && preg_match('/^[0-9]{9}$/', $_POST['tel'])){ echo 'valid';}else {echo 'invaild';}?>" type="text" name="tel" value="<?php if(isset($_POST["tel"])){echo $_POST['tel'];} ?>"><br>
        Kwota
        <input class="<?php if (isset($_POST["kwota"]) && preg_match('/^[0-9]+$/' ,$_POST['kwota'])){ echo 'valid';}else {echo 'invaild';}?>" type="text" name="kwota" value="<?php if(isset($_POST["kwota"])){echo $_POST['kwota'];} ?>"><br>
        <input type="submit" value="Wyślij"><br>

<?php
    if (isset($_POST["adres"]) && !preg_match('/^[A-Z][a-z]+ [0-9]+ [A-Z][a-z]+$/', $_POST['adres'])) {
        echo 'Błędna formuła Adresu wprowadz adres w postaci Ulica numer Miasto <br>'; 
    }
    if (isset($_POST["nr"]) && !preg_match('/^[0-9]{4}-[0-9]{4}-[0-9]{4}-[0-9]{4}$/', $_POST['nr'])) {
        echo 'Błędna formuła Numeru wprowadz nr w postaci XXXX-XXXX-XXXX-XXXX <br>';
    }
    if (isset($_POST["data"]) && !preg_match('/^[0-1][0-9]\/[0-2][0-9][0-9][0-9]$/', $_POST['data'])) {
        echo 'Błędna formuła wprowadz adres w postaci MM/RRRR <br>';
    };
?>
</html>