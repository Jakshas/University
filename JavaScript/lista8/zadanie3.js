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
        let serv = await sql.connect(config);
        let del = await serv.request()    
            .query("delete from OSOBA where Name='Jan'")
        let up = await serv.request()
            .query("update OSOBA set Surname = 'Jakub' where Name='Jan'")
    } catch (err) {
        console.log(err);
    }
}

Wstaw()