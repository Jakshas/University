// tabele sa stworzone podobnie do tych z wykladu

const sql = require('mssql')

const config = {
    user: 'js',
    password: '1234',
    server: 'localhost',
    database: 'lista8',
}

const Wstaw = async function(data) {
    try {
        let serv = await sql.connect(config);
        let wynik = await serv.request()
            .query("insert into MIEJSCE_PRACY values('CEO'); SELECT SCOPE_IDENTITY()")
        let x = Object.values(wynik.recordset[0])[0]
        let rq = new sql.Request(serv)
        rq.input("job_id", x)
        await rq
            .query("insert into OSOBA3 values('Jakub', 'Szajner', 'M', '2000-01-01', @job_id)")
    } catch (err) {
        console.log(err);
    }
}

Wstaw()