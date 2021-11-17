<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Zgloszenie.aspx.cs" Inherits="Zadanie4.Zgloszenie" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            Imie
            <asp:TextBox runat="server" ID="Imie"></asp:TextBox>
            Nazwisko
            <asp:TextBox runat="server" ID="Nazwisko"></asp:TextBox>
            Data
            <asp:TextBox runat="server" ID="Data"></asp:TextBox>
            Zajecia
            <asp:TextBox runat="server" ID="Zajecia"></asp:TextBox>
            Zestaw
            <asp:TextBox runat="server" ID="Zestaw"></asp:TextBox>
            <br/>
            1<asp:TextBox runat="server" ID="TextBox1" onkeydown = "return (!(event.keyCode>=65) && event.keyCode!=32);"></asp:TextBox>
            2<asp:TextBox runat="server" ID="TextBox2" onkeydown = "return (!(event.keyCode>=65) && event.keyCode!=32);"></asp:TextBox> 
            3<asp:TextBox runat="server" ID="TextBox3" onkeydown = "return (!(event.keyCode>=65) && event.keyCode!=32);"></asp:TextBox>
            4<asp:TextBox runat="server" ID="TextBox4" onkeydown = "return (!(event.keyCode>=65) && event.keyCode!=32);"></asp:TextBox>
            5<asp:TextBox runat="server" ID="TextBox5" onkeydown = "return (!(event.keyCode>=65) && event.keyCode!=32);"></asp:TextBox>
            6<asp:TextBox runat="server" ID="TextBox6" onkeydown = "return (!(event.keyCode>=65) && event.keyCode!=32);"></asp:TextBox>
            7<asp:TextBox runat="server" ID="TextBox7" onkeydown = "return (!(event.keyCode>=65) && event.keyCode!=32);"></asp:TextBox>
            8<asp:TextBox runat="server" ID="TextBox8" onkeydown = "return (!(event.keyCode>=65) && event.keyCode!=32);"></asp:TextBox>
            9<asp:TextBox runat="server" ID="TextBox9" onkeydown = "return (!(event.keyCode>=65) && event.keyCode!=32);"></asp:TextBox>
            10<asp:TextBox runat="server" ID="TextBox10" onkeydown = "return (!(event.keyCode>=65) && event.keyCode!=32);"></asp:TextBox>
            <br/>
            <asp:Button runat="server" Text="Wyslij" ID="buton" />
        </div>
    </form>
</body>
</html>
