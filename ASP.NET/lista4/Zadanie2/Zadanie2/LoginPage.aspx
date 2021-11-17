<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="LoginPage.aspx.cs" Inherits="Zadanie2.LoginPage" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            Login: <asp:TextBox ID="login" runat="server"></asp:TextBox>
        </div>
         <div>
            Hasło: <asp:TextBox ID="haslo" runat="server"></asp:TextBox>
        </div>
         <div>
            <asp:Button runat="server" ID="bt" Text="Zaloguj" OnClick="bt_Click" />        
        </div>
        <div>
            <asp:Button runat="server" ID="regbt" Text="Zaloguj" OnClick="regbt_Click" />        
        </div>
    </form>
</body>
</html>
