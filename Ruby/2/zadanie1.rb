class Funkcja
    def initialize(&f)
        @f = f
    end
    def oblicz(arg)
        @f.call(arg)
    end
    def miejsca_zerowe(a,b,e) #z Darboux
        m_z = 0;  kroki = []
        kroki.push(a*1.0)
        it=(a-b)/e
        while a < b do
            kroki.push(a + e)
            a += e
        end
        if kroki.last() > b*1.0
            kroki.delete(kroki.last())
        end
        (1 ... kroki.length()).each{ |i|
            (@f.call(kroki[i])) * (@f.call(kroki[i-1])) > 0 ? m_z += 0 : m_z += 1
        }
        return m_z
    end

    def pole(a,b) #złozony wzór trapezów
        suma = 0.0
        suma += @f.call(a)
        suma += @f.call(b)
        (1 ... 10000).each{ |i|
            suma += @f.call(a + ((b-a) / 10000.0) * i) }
        suma = suma * ((b-a) / 10000.to_f)
        return suma
    end
    def pochodna(punkt)
        (@f.call(punkt + 0.00001) - @f.call(punkt)) / 0.00001
    end
end

test = Funkcja.new{ | x | x*x*Math.sin(x)}
puts(test.oblicz(2))
puts(test.pochodna(2))
puts(test.pole(2,4))
puts(test.miejsca_zerowe(2,4,0.1))

test2 = Funkcja.new{|x| Math.sin(x)}
puts(test2.miejsca_zerowe(0,10,0.001)) 