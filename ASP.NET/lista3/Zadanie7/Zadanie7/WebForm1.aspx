﻿<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="Zadanie7.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <asp:FileUpload ID="FileUpload1" runat="server" /> 
            <asp:Button ID="button1" runat="server" Text="Wyślij formularz na serwer" OnClick="UploadButton_Click"/> 
        </div>
    </form>
</body>
</html>
