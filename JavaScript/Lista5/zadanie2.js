const fs = require('fs');
const https = require('https');

(async function() {
    const pfx = await fs.promises.readFile('zadanie2.pfx');
    let server = https.createServer({
        pfx: pfx,
        passphrase: '123'
    },
    (req, res) => {
        res.setHeader('Content-type', 'text/html; charset=utf-8');
        res.end('zadanie2');
    }).listen(2000);
    console.log("started");
})();