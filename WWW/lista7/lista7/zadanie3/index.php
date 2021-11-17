<?php
	$IsPostFormData = (isset($_POST["sent"]) && ($_POST["sent"]=="y"));
	$IsGetFormData = (isset($_GET["sent"]) && ($_GET["sent"]=="y"));
	$UploadDir="uploaded/";
	$UploadCodes = array( "UPLOAD_ERR_OK", "UPLOAD_ERR_INI_SIZE", "UPLOAD_ERR_FORM_SIZE", "UPLOAD_ERR_PARTIAL", "UPLOAD_ERR_NO_FILE" );
	$MaxFileSize=100000;
	?>
<?php
    if (isset($_GET['delete'])) {
        unlink($_GET['delete']);
    }
?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
"http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<title>Zadanie 3</title>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
</head>
<body>
<div align="center">
<?php

if( $IsPostFormData )
{
	$UploadFile = $UploadDir.$_FILES["plik"]["name"];
	if(move_uploaded_file($_FILES["plik"]["tmp_name"], $UploadFile))
	{
		echo "Plik został poprawnie uploadowany i skopiowany w nowe miejsce";
	}
	else
    {
    	echo "Błąd przy uploadowaniu";
    }
}
?>
	
<form enctype="multipart/form-data" action="zadanie3.php" 
		 method="post" name="formularz">
<input type="hidden" name="MAX_FILE_SIZE" value="<?php echo $MaxFileSize;?>">
<input type="file" name="plik" size="200">
<input type="submit" value="Wyślij" name="Submit">
<input type="hidden" name="sent" value="y">
</form>
<br>

<?php
	$Files = scandir($UploadDir);
	for($i=2; $i < count($Files); $i++)
	{
		echo $Files[$i];
		echo '<br><a href="?delete=';
		echo $UploadDir;
		echo $Files[$i];
		echo '">Delete file</a><br><br>';

	}
?>

</div>
</body>
</html>