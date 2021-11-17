class Funkcja2
    def initialize(&blok)
        @f = blok
    end

    def value(x, y)
        @f.call(x,y)
    end

    def objetosc(a, b, c, d)
        v = 0
        n = (b-a) / 1000.0 
        m = (d-c) / 1000.0 
        (1 ... 1000).each do |i|
            (1 ... 1000).each do |j|
                v += @f.call(a + n * i + n/2.0, c + m * j + m/2.0)
            end
        end
        return v * n * m
    end

    def poziomica(a,b,c,d,poz,wysokosc) #z tw Darboux
        xy = []; it = 0; kroki = []
        cstart = c
        kroki.push([a*1.0,c*1.0])
        while a + poz <= b do
            a += poz
            while c + poz < d do
                c += poz
                kroki.push([a, c])
            end
            c = cstart
        end
        
        (1 ... kroki.length()).each{ |i|
            pom = @f.call(kroki[i][0],kroki[i][1]) - wysokosc
            if pom * (@f.call(kroki[i][0]-poz, kroki[i][1]) - wysokosc) < 0
                xy.push([kroki[i][0],kroki[i][1]])
            elsif pom * (@f.call(kroki[i][0]+poz, kroki[i][1]) - wysokosc) < 0
                xy.push([kroki[i][0],kroki[i][1]])
            elsif pom * (@f.call(kroki[i][0], kroki[i][1] - poz) - wysokosc) < 0
                xy.push([kroki[i][0],kroki[i][1]])
            elsif pom * (@f.call(kroki[i][0], kroki[i][1] + poz) - wysokosc) < 0
                xy.push([kroki[i][0],kroki[i][1]]) 
            end
        }
        return xy
    end
    
end

test = Funkcja2.new{|x,y| x+y}
puts(test.value(1,3))
puts(test.objetosc(0,3,0,3))
print(test.poziomica(0.0,1.0,0.0,1.0,0.01,1.9))