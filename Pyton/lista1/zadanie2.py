def is_palindrom(text):
    text = ''.join(e for e in text if e.isalnum()).lower()
    dlugosc = len(text)
    for i in range(0,dlugosc//2):
        if text[i] != text[dlugosc-i-1]:
            return False
    return True

print(is_palindrom("Eine güldne, gute Tugend: Lüge nie!"))