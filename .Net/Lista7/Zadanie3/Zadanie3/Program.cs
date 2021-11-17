using System;
using System.IO;
using System.IO.Compression;
using System.Security.Cryptography;

namespace Zadanie3
{
    class Program
    {
        static void Main(string[] args)
        {
            string file = File.ReadAllText("C:/Projekty/University/dotNet/Lista7/Zadanie3/file.txt");
            using Aes mya = Aes.Create();
            byte[] encrypted;
            using (Aes pom = Aes.Create())
            {
                pom.Key = mya.Key;
                pom.IV = mya.IV;
                using ICryptoTransform e = pom.CreateEncryptor(pom.Key, pom.IV);
                using MemoryStream mss = new MemoryStream();
                using CryptoStream css = new CryptoStream(mss, e, CryptoStreamMode.Write);
                using GZipStream zs = new GZipStream(css, CompressionMode.Compress, false);
                using (StreamWriter se = new StreamWriter(zs))
                {
                    se.Write(file);
                }
                encrypted = mss.ToArray();
            }
            string txt = null;
            using (Aes pom = Aes.Create())
            {
                pom.Key = mya.Key;
                pom.IV = mya.IV;
                using ICryptoTransform d = pom.CreateDecryptor(pom.Key, pom.IV);
                using MemoryStream msd = new MemoryStream(encrypted);
                using CryptoStream csd = new CryptoStream(msd, d, CryptoStreamMode.Read);
                using GZipStream zs = new GZipStream(csd, CompressionMode.Decompress);
                using StreamReader sr = new StreamReader(zs);
                txt = sr.ReadToEnd();
            }
            Console.WriteLine(file);
            Console.WriteLine(txt);
        }
    }
}
