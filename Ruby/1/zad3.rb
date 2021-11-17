class Jawne
    def initialize(napis)
        @napis = napis
    end

    def zaszyfruj(klucz)
        zwrot = ""
        @napis.each_char do |literka|
                zwrot += klucz[literka]
            end
        return Zaszyfrowane.new(zwrot)
    end

    def reprezentacja()
        return @napis
    end
end


class Zaszyfrowane
    def initialize(napis)
        @napis = napis
    end

    def odszyfruj(klucz)
        klucz = klucz.invert
        zwrot = ""
        @napis.each_char do |literka|
                zwrot += klucz[literka]
            end
        return Jawne.new(zwrot)
    end

    def reprezentacja()
        return @napis
    end
end

S = {" " => " ", "a" => "b", "b" => "c", "c" => "d", "d" => "e",
    "e" => "f", "f" => "g", "g" => "h", "h" => "i", "i" => "j",
    "j" => "k", "k" => "l", "l" => "m", "m" => "n", "n" => "o",
    "o" => "p", "p" => "r", "r" => "s", "s" => "t", "t" => "u",
    "u" => "v", "v" => "w", "w" => "x", "x" => "y", "y" => "z", "z" => "a"}

jeszczejawne = Jawne.new("ala ma kota")
juzzaszyfrowane = jeszczejawne.zaszyfruj(S)
puts(juzzaszyfrowane.reprezentacja)

odszyfrowane = juzzaszyfrowane.odszyfruj(S)
puts(odszyfrowane.reprezentacja)