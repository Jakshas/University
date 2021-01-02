process.stdin.setEncoding('utf8'); 
console.log("Podaj imie");
process.stdin.on('readable',() => { 
    var chunk = process.stdin.read(); 
    if (chunk !== null) { 
    process.stdout.write("witaj "+ chunk); 
    } 
}); 

process.stdin.on('end',() => { 
    process.stdout.write('end'); 
}); 