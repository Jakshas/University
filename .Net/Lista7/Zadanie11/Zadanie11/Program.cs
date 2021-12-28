using Microsoft.CSharp;
using System;
using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Zadanie11
{
    class Program
    {
        static void Main(string[] args)
        {
            string program = $"public class Program1 {{" +
                                $" public int foo() {{";
            program += Console.ReadLine();
            program += "}" +
                "}";
            CompilerResults compiled = (new CSharpCodeProvider()).CompileAssemblyFromSource(new CompilerParameters(), program);
            foreach (var i in compiled.Errors)
            {
                Console.WriteLine(i.ToString());
            }
            var type = compiled.CompiledAssembly.GetType("Program1");
            var method = type.GetMethod("foo");
            Console.WriteLine(method.Invoke(Activator.CreateInstance(type), null));
            Console.ReadLine();
        }
    }
}
