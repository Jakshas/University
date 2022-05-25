using Microsoft.VisualStudio.TestTools.UnitTesting;
using System.Threading;
using System;

namespace TestProject1
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void SingletonTest()
        {
            var s1 = Singleton.Instance();
            var s2 = Singleton.Instance();

            Assert.AreEqual(s1, s2);
        }
        [TestMethod]
        public void ThreadSingletonTest()
        {
            ThreadSingleton s1 = null;
            ThreadSingleton s2 = null;

            var thread1 = new Thread(() => s1 = ThreadSingleton.Instance());
            var thread2 = new Thread(() => s2 = ThreadSingleton.Instance());

            thread1.Start();
            thread2.Start();

            thread1.Join();
            thread2.Join();

            Assert.AreNotEqual(s1, s2);
        }
        [TestMethod]
        public void TimeSingletonTest()
        {
            var s1 = TimeSingleton.Instance();
            Thread.Sleep(6000);
            var s2 = TimeSingleton.Instance();

            Assert.AreNotEqual(s1, s2);
        }
    }
}