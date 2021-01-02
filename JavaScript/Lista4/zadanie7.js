    var fs= require('fs');
    const util = require('util')
    fs.readFile('zadanie3a.js', 'utf-8', function(err, dataa) {
        //wypisz(dataa)
    });

    function wypisz(params) {
        console.log(params);
    }
    function fspromise( path, enc) {
        return new Promise( (res, rej) =>{
            fs.readFile( path, enc, (err, data) =>{
                if( err)
                    rej(err);
                    res(data);
                });
            });
        }
        
        // fspromise('zadanie3a.js', 'utf-8')
        //     .then( data=>{
        //         console.log( `data: ${data}`);
        //     })
        //     .catch( err=>{
        //         console.log( `err: ${err}`);
        //     })

        const u= util.promisify(fs.readFile)

        // u('zadanie3a.js', 'utf-8', function(err, dataa){
        //     wypisz(dataa)
        // })
        //     .then( data=>{
        //             console.log( `data: ${data}`);
        //         });

    async function main() {
        var a= await fspromise('zadanie3a.js', 'utf-8');
        console.log(a);
    }


async function trzeci() {
    try {
        var a= await fs.promises.readFile('zadanie3a.js', 'utf-8');
        wypisz(a);
    } catch (error){
        console.error(error);
    }
}
trzeci()

// fs.promises.readFile('zadanie3a.js', 'utf-8', function(err, dataa) {
//     wypisz(dataa)
// })
// .then( data=>{
//                 console.log( `data: ${data}`);
//             })
  

//     .catch(err => { 
//         console.log(err) 
//     }) 


    //main();