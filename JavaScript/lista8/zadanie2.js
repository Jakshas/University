// tabela z zad1

const sql = require('mssql')

const config = {
    user: 'js',
    password: '1234',
    server: 'localhost',
    database: 'lista8',
}

const Wstaw = async function(data) {
    try {
        let serv = await sql.connect(config)
        let wynik = await serv.request()
            .query("insert into OSOBA values('Jan', 'Kowalski', 'M', '2000-01-01'); SELECT SCOPE_IDENTITY()");
            console.log(wynik);
        let x = Object.values(wynik.recordset[0])[0] 
        console.log(x)
    } catch (err) {
        console.log(err);
    }
}

Wstaw()