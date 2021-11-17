def ret( positions, length ):
    starts = length - positions[0] 
    ans = set()
    if len(positions)==1: 
        ans = { ( "." * i + "#" * positions[0] + "." * (starts-i) ) for i in range( starts+1 ) }
    else:
        for i in range(length-positions[0]): 
            for sol in ret(positions[1:],starts-i-1):
                ans.add( "." * i + "#" * positions[0] + "." + sol )
    return ans

def combinations( rowsInfo, h, w ):
    return [ ret( rowsInfo[i], h ) for i in range(w) ]

def checkfields(  positions, length ):
    a = [ set() for _ in range( length ) ]
    for pos in positions:
        for i in range( len( pos ) ):
              a[i].add( pos[i] )
    return a 

def delete( rowstocheck, clostocheck, w, h ):
    for i in range(10):
        nextIter = False
        for rid in range(len(rowstocheck)): 
            checkedrow = checkfields(rowstocheck[rid], h) 
            for coll in range(len(checkedrow)): 
                if(len( checkedrow[coll] ) == 1): 
                    (char,) = checkedrow[coll]    
                    d = []
                    for p in clostocheck[coll]: 
                        if( p[rid] != char):
                            d.append(p)
                    for dd in d:
                        clostocheck[coll].remove( dd )
        for cid in range(len(clostocheck)):
            checkedcol = checkfields( clostocheck[cid], w )
            for roww in range(len(checkedcol)):
                if (len(checkedcol[roww]) == 1):
                    (char,) = checkedcol[roww]
                    d = []
                    for p in rowstocheck[roww]:
                        if( p[cid] != char ):
                            d.append(p)
                    for dd in d:
                        rowstocheck[roww].remove( dd )
    return rowstocheck

def count(row):
    count = []
    l = 0
    for i in range(len(row)):
        if(row[i] == '#'):
            l += 1
        elif(l != 0):
            count.append( l )
            l = 0
    if(row[len(row) - 1] == '#'):
        count.append(l)
    return count

def perm(tab):
    p = set()
    for el in tab:
        if len(p) == 0:
            for e in el:
                p.add(e)
        else:
            a = set()
            for e in el:
                for pp in p:
                    a.add(pp +" "+ e)
            p = a
    a = []
    for el in p:
        h = el.split(" ")
        a.append(h)
    return a           

def findgood(betterrows, cols, w):
    for el in betterrows:
        it = 0
        for i in range(w):
            string = ''
            for j in range(len( el )):
                string += el[j][i]
            if(count(string) == cols[i]):
                it = it + 1
        if(it == w):
            return el

rows1, cols1 = (2, 1, 3, 1), (1, 3, 1, 2)
rows = [[x] for x in cols1]
cols = [[x] for x in rows1]
w = len(cols)
h = len(rows)
rowstocheck = combinations(rows, h, w)
colstocheck = combinations(cols, w, h)
betterrows = delete(rowstocheck, colstocheck, w, h)
odp = findgood(perm( betterrows ), cols, h)
pr = ''
for el in odp:
    pr = pr + el + '\n'
print(pr)
