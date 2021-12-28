import unittest
import types
import z1
import z2


class testy1(unittest.TestCase):
    listaP = ["Kajak", "Eine güldne, gute Tugend: Lüge nie!"]
    listaN = ["slowo", "inneslowo"]

    def testPoprawne(self):
        """Wykonaj test na poprawnych"""
        for t in self.listaP:
            self.assertEqual(True, z2.is_palindrom(
                t), "Poprwnie stwierdził ze poprawne")

    def testNiePoprawne(self):
        """Wykonaj test na niepoprawnych"""
        for t in self.listaN:
            self.assertEqual(False, z2.is_palindrom(
                t), "Poprwnie stwierdził ze niepoprawne")

    def testPusty(self):
        """Wykonaj test na pustych"""
        self.assertEqual(True, z2.is_palindrom(
            ""), "Poprwnie stwierdził ze puste to palindrom")


class testy(unittest.TestCase):
    listaP = [(4, 2), (16, 4), (225, 15), (10000, 100)]
    listaN = [(6, 3), (30, 6), (250, 16), (10001, 101)]
    listaZ = [(-1, 0), (0, 0)]

    def testPierwiastekCaly(self):
        """Wykonaj test na poprawnych całych ułamkach"""
        for t1, t2 in self.listaP:
            self.assertEqual(t2, z1.pierwiastek(t1))

    def testZaokraglenie(self):
        """Wykonaj test na niepoprawnych"""
        for t1, t2 in self.listaN:
            self.assertEqual(t2, z1.pierwiastek(t1))

    def testNiepoprawne(self):
        """Wykonaj test na niepoprawnych"""
        for t1, t2 in self.listaZ:
            self.assertEqual(t2, z1.pierwiastek(t1))


if __name__ == "__main__":
    unittest.main()
